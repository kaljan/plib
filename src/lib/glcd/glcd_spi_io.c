/**
 * @file 	glcd_spi_io.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "glcd_spi_io.h"

/**
 *
 * @param config
 * @return
 */
glcd_io_t * glcd_get_interface(void * config) {
	hal_spi_dsc_t * spi_dsc = hal_spi_get_context(HAL_SPI6);
	if (spi_dsc) {
		spi_dsc->spi_cfg = (hal_spi_cfg_t *)config;
		sh1106_glcd_spi_io.spi_dsc = spi_dsc;
		return &sh1106_glcd_io;
	}
	return NULL;
}

/**
 *
 * @param context
 * @return
 */
int glcd_spi_io_connect(void * context) {
	int ret = -1;
	if (context) {
		gcdi_spi_io_t * interface = (gcdi_spi_io_t *)context;
		if ((ret = hal_spi_connect(interface->spi_dsc, &glcd_spi6_handler)) == 0) {
			hal_gpio_init(interface->gcdi_cs);
			hal_gpio_init(interface->gcdi_dc);
			hal_gpio_if_set_value(interface->gcdi_cs, true);
			hal_gpio_if_set_value(interface->gcdi_dc, true);
		}
	}
	return ret;
}

/**
 *
 * @param context
 */
void glcd_spi_io_disconnect(void * context) {
	if (context) {
		gcdi_spi_io_t * interface = (gcdi_spi_io_t *)context;
		hal_spi_disconnect(interface->spi_dsc);
		hal_gpio_deinit(interface->gcdi_cs);
		hal_gpio_deinit(interface->gcdi_dc);
		interface->spi_dsc->spi_cfg = NULL;
	}
}

/**
 *
 * @param context
 * @param handler
 * @param data
 * @param size
 * @return
 */
int glcd_spi_io_write_data(void * context,
	hal_callback_t * handler, void * data, size_t size) {
	int ret = -1;
	if (context) {
		gcdi_spi_io_t * interface = (gcdi_spi_io_t *)context;
		if (handler) {
			interface->callback = handler->callback;
			interface->on_failed = handler->on_failed;
			interface->context = handler->object;
		}
		hal_gpio_if_set_value(interface->gcdi_dc, true);
		hal_gpio_if_set_value(interface->gcdi_cs, false);
		ret = hal_spi_transfer(interface->spi_dsc, data, size);

	}
	return ret;
}

/**
 *
 * @param context
 * @param handler
 * @param data
 * @param size
 * @return
 */
int glcd_spi_io_write_command(void * context,
	hal_callback_t * handler, void * data, size_t size) {
	int ret = -1;
	if (context) {
		gcdi_spi_io_t * interface = (gcdi_spi_io_t *)context;
		if (handler) {
			interface->callback = handler->callback;
			interface->on_failed = handler->on_failed;
			interface->context = handler->object;
		}
		hal_gpio_if_set_value(interface->gcdi_dc, false);
		hal_gpio_if_set_value(interface->gcdi_cs, false);
		ret = hal_spi_transfer(interface->spi_dsc, data, size);
	}
	return ret;
}

/**
 *
 * @param arg
 */
void glcd_spi_io_transfer_complete(volatile void * arg) {
	if (arg) {
		gcdi_spi_io_t * context = (gcdi_spi_io_t *)arg;
		hal_gpio_if_set_value(context->gcdi_cs, true);
		if (context->callback) {
			context->callback(context->context);
		}
	}
}

/**
 *
 * @param arg
 * @param error
 */
void glcd_spi_io_err_handler(volatile void *arg, hal_error_t error) {
	if (arg) {
		gcdi_spi_io_t * context = (gcdi_spi_io_t *)arg;
		if (context->on_failed) {
			context->on_failed(context->context, error);
		}
	}
}
