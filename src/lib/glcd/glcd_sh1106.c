/**
 * @file 	glcd_sh1106.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "glcd_sh1106.h"

// TODO implement power on off
// TODO implement reset
// TODO implement config
// TODO implement error handler

/**
 *
 * @return
 */
glcd_t * glcd_get_context(void) {
	if (!sh1106_driver.initialized) {
		return &sh1106_glcd_interface;
	}
	return NULL;
}

/**
 *
 * @param context
 * @return
 */
_Bool sh1106_busy(volatile void * context) {
	if (context) {
		sh1106_driver_t * driver = (sh1106_driver_t *)context;
		return driver->busy;
	}
	return false;
}

/**
 *
 * @param arg
 * @return
 */
_Bool sh1106_tim_callback(volatile void * arg) {
	if (arg) {
		sh1106_driver_t * context = (sh1106_driver_t *)arg;
		int bytes = -1, offset = -1;
		if (context->state == SH1106_IDLE) {
			hal_gpio_if_set_value(context->reset_pin, true);
			context->state = SH1106_RESET;
			return true;
		}

		if (context->state == SH1106_RESET) {
			context->glcd_io = glcd_get_interface(context->spi_cfg);
			if (glcd_io_connect(context->glcd_io) == 0) {
				context->state = SH1106_CFGR;
				bytes = 13;
				offset = 0;
			}
		} else if (context->state == SH1106_CFGR) {
			context->state = SH1106_PCFGR;
			bytes = 2;
			offset = 13;
		} else if (context->state == SH1106_PCFGR) {
			context->state = SH1106_PWROFF;
			bytes = 15;
			offset = 1;
		} else if (context->state == SH1106_PWROFF) {
			context->state = SH1106_PWRON;
			context->initialized = true;
			context->busy = false;
			if (context->callback) {
				context->callback(context->arg);
			}
			return false;
		}
		if (bytes > 0) {
			glcd_io_write_command(context->glcd_io,
				context->init_handler, context->cfg + offset, bytes);
		}
	}
	return false;
}

/**
 *
 * @param arg
 */
void sh1106_spi_callback(volatile void * arg) {
	if (arg) {
		sh1106_driver_t * context = (sh1106_driver_t *)arg;
		hal_tim_run_delay(context->timer, 100000,
			sh1106_tim_callback, (volatile void *)context);
	}
}

/**
 *
 * @param context
 * @param handler
 * @return
 */
int sh1106_init(void * context, hal_callback_t * handler) {
	int ret = -1;
	if (context) {
		ret = 1;
		sh1106_driver_t * driver = (sh1106_driver_t *)context;
		if (!driver->busy && !driver->initialized) {
			ret = 0;
			hal_gpio_init(driver->reset_pin);
			hal_gpio_if_set_value(driver->reset_pin, false);
			if ((ret = hal_tim_run_delay(driver->timer, 15,
				sh1106_tim_callback, (volatile void *)driver)) == 0) {
				driver->busy = true;
				if (handler) {
					driver->callback = handler->callback;
					driver->arg = handler->object;
				}
			}
		}
	}
	return ret;
}

/**
 *
 * @param context
 */
void sh1106_write_callback(volatile void * context) {
	if (context) {
		sh1106_driver_t * driver = (sh1106_driver_t *)context;
		if (driver->state == SH1106_ADDR) {
			if (glcd_io_write_data(
				driver->glcd_io, driver->data_handler,
				driver->curr, driver->width) == 0) {
				driver->page++;
				if (driver->page < 8) {
					driver->curr += driver->width;
					driver->state = SH1106_DATA;
					return;
				}
				driver->page = 0;
				driver->state = SH1106_PWRON;
			}
			return;
		}
		if (driver->state == SH1106_DATA) {
			driver->cmd[0] = 0xB0 + driver->page;
			driver->cmd[1] = 0x00 + (0x0F & driver->offset);
			driver->cmd[2] = 0x10 + ((0xF0 & driver->offset) >> 4);
			if (glcd_io_write_command(
				driver->glcd_io, driver->data_handler,
				driver->cmd, driver->cmd_size) == 0) {
				driver->state = SH1106_ADDR;
				return;
			}
		}
		if (driver->state == SH1106_PWRON) {
			driver->busy = false;
			if (driver->callback) {
				driver->callback(driver->arg);
			}
		}
	}
}

/**
 *
 * @param context
 * @param handler
 * @param buffer
 * @return
 */
int sh1106_write_buffer(void * context,
	hal_callback_t * handler, buffer_t * buffer) {
	sh1106_driver_t * driver = (sh1106_driver_t *)context;
	if (driver && !driver->busy && driver->initialized &&
		handler && buffer && driver->cmd) {
		driver->callback = handler->callback;
		driver->arg = handler->object;
		driver->curr = buffer->data;
		driver->cmd[0] = 0xB0 | (0x0F & driver->page);
		driver->cmd[1] = 0x0F & driver->offset;
		driver->cmd[2] = 0x10 | ((0xF0 & driver->offset) >> 4);
		driver->busy = true;
		driver->state = SH1106_ADDR;
		if (glcd_io_write_command(
			driver->glcd_io, driver->data_handler,
			driver->cmd, driver->cmd_size) == 0) {
			return 0;
		}
	}
	return -1;
}

/**
 *
 * @param arg
 * @param error
 */
void sh1106_on_failed(volatile void *arg, hal_error_t error) {
	if (arg) {
		sh1106_driver_t * driver = (sh1106_driver_t *)arg;
		if (driver->on_failed) {
			driver->on_failed(driver->arg, error);
		}
	}
}

/*
Собирательный образ инициализации

1. Задержка 100 мс
2. Reset=0
3. Задержка 15 мкс
4. Reset=1
5. Задержка 15 мкс
6. Отправка конфигурации
7. Задержка 100 мc
8. Отправка команды включения питания
9. Задержка 100 мc
10. Отправка команды на включение дисплея
11. Задержка на 50 мс
12. Вывод демо изображения.
13. Задержка 1 с.
 */
