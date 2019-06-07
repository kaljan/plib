/**
 * @file 	hal_spi.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "hal_spi.h"
#include "hwprof.h"

/**
 *
 * @param id
 * @return
 */
hal_spi_dsc_t * hal_spi_get_context(int id) {
	hal_spi_dsc_t ** list = spi_list;
	while (*list) {
		if (((*list)->id == id)) {
			if ((*list)->spi_cfg) {
				return *list;
			}
			break;
		}
	}
	return *list;
}

/**
 *
 * @param context
 */
static void hal_spi_reset(hal_spi_dsc_t * context) {
	if (context && context->rcc_clk_enable) {
		context->rcc_clk_enable(false);
	}
}

/**
 *
 * @param context
 * @return
 */
static _Bool hal_spi_configure(hal_spi_dsc_t * context) {
	if (context) {
		if (context->rcc_clk_enable) {
			context->rcc_clk_enable(true);
		}

		return hal_spi_set_config(context->spi, context->spi_cfg);
	}
	return false;
}

/**
 *
 * @param context
 * @return
 */
static int hal_spi_init(hal_spi_dsc_t * context) {
	int ret = -1;
	if (context && context->spi_cfg) {
		if (!hal_spi_configure(context)) {
			return -1;
		}

		do {
			if (context->spi_cfg->rx_enabled) {
				if ((ret = hal_dma_configure(
					context->rx_dma_dsc, context->rx_dma_config)) != 0) {
					break;
				}
				hal_gpio_init(context->miso);
			}

			if (context->spi_cfg->tx_enabled) {
				if (context->tx_dma_config) {
					context->tx_dma_config->tcie = !context->spi_cfg->rx_enabled;
				}
				if ((ret = hal_dma_configure(context->tx_dma_dsc, context->tx_dma_config)) != 0) {
					break;
				}
				hal_spi_tx_dma_enable(context->spi, true);
				hal_gpio_init(context->mosi);
			}

			hal_gpio_init(context->sck);
			context->busy = false;
			return ret;
		} while (0);
		hal_spi_reset(context);
	}
	return ret;
}

/**
 *
 * @param context
 * @return
 */
_Bool hal_spi_get_status(void * context) {
	if (context) {
		return ((hal_spi_dsc_t *)context)->busy;
	}
	return false;
}

/**
 *
 * @param dsc
 * @param handler
 * @return
 */
int hal_spi_connect(hal_spi_dsc_t * dsc, hal_interface_t * handler) {
	int ret = -1;
	if (dsc && handler) {
		if ((ret = hal_spi_init(dsc)) == 0) {
			dsc->transfer_complete = handler->transfer_complete;
			dsc->on_received = handler->on_received;
			dsc->err_handler = handler->on_failed;
			dsc->arg = handler->context;
		}
	}
	return ret;
}

/**
 *
 * @param context
 */
void hal_spi_disconnect(hal_spi_dsc_t * context) {
	if (context) {
		hal_gpio_deinit(context->miso);
		hal_gpio_deinit(context->mosi);
		hal_gpio_deinit(context->sck);
		hal_spi_reset(context);
	}
}

/**
 *
 * @param context
 * @param data
 * @param size
 * @return
 */
int hal_spi_transfer(hal_spi_dsc_t * context, void * data, size_t size) {
	int ret = -1;
	if (context && context->spi_cfg) {
		ret = 1;
		if (!context->busy) {
			ret = 0;
			if (context->spi_cfg->rx_enabled) {
				if (context->rx_buffer) {
					ret = hal_dma_transfer(context->rx_dma_dsc,
						context->rx_buffer->data, size);
				} else {
					ret = -1;
				}

			}

			if ((ret == 0) && context->spi_cfg->tx_enabled) {
				ret = hal_dma_transfer(context->tx_dma_dsc, data, size);
			}
			if (ret == 0) {
				context->busy = true;
			}
		}
	}
	return ret;
}

/**
 *
 * @param spi
 * @return
 */
static _Bool hal_spi_wait_busy(SPI_TypeDef * spi) {
	if (spi) {
		int timeout = 1000000;
		while (spi->SR & SPI_SR_BSY) {
			timeout--;
			if (timeout < 0) {
				return false;
			}
		}
		return true;
	}
	return false;
}

/**
 *
 * @param arg
 */
void hal_spi_tx_dma_handler(volatile void * arg) {
	if (arg) {
		volatile hal_spi_dsc_t * context = (volatile hal_spi_dsc_t *)arg;
		hal_spi_wait_busy(context->spi);
		context->busy = false;
		if (context->transfer_complete) {
			context->transfer_complete(context->arg);
		}
	}
}

/**
 *
 * @param arg
 */
void hal_spi_tx_dma_te_handler(volatile void *arg) {
	if (arg) {
		volatile hal_spi_dsc_t * context = (volatile hal_spi_dsc_t *)arg;
		if (context->err_handler) {
			context->err_handler(context->arg, HAL_ERR_DMA_TE);
		}
	}
}

/**
 *
 * @param arg
 */
void hal_spi_tx_dma_dme_handler(volatile void *arg) {
	if (arg) {
		volatile hal_spi_dsc_t * context = (volatile hal_spi_dsc_t *)arg;
		if (context->err_handler) {
			context->err_handler(context->arg, HAL_ERR_DMA_DME);
		}
	}
}

/**
 *
 * @param arg
 */
void hal_spi_rx_dma_handler(volatile void * arg) {
	if (arg) {
		volatile hal_spi_dsc_t * context = (volatile hal_spi_dsc_t *)arg;
		if (context->on_received) {
			context->on_received(context->arg,
				context->rx_buffer);
		}
		context->busy = false;
	}
}

#if 0
static inline _Bool hal_spi_irq_tx_handler(
	SPI_TypeDef * spi, buffer_t * buffer,
	void (*callback)(volatile void *),
	volatile void * context) {
	if (spi && buffer && callback &&
		(spi->CR2 & SPI_CR2_TXEIE) &&
		(spi->SR & SPI_SR_TXE) &&
		buffer && buffer->data) {
		if (!buffer->curr) {
			buffer->curr = buffer->data;
		}
		if (buffer->bytes > 0) {
			spi->DR = *((uint8_t *)buffer->curr);
			buffer->bytes--;
			buffer->curr++;
			return true;
		}
		callback(context);
	}
	return false;
}

static inline _Bool hal_spi_irq_rx_handler(
	SPI_TypeDef * spi, buffer_t * buffer,
	void (*callback)(volatile void *, buffer_t *),
	volatile void * context) {

	if (spi && buffer && callback &&
		(spi->CR2 & SPI_CR2_RXNEIE) &&
		(spi->SR & SPI_SR_RXNE) &&
		buffer && buffer->data) {
		if (buffer->bytes < buffer->size) {
			*(((uint8_t *)(buffer->data)) + buffer->bytes) = spi->DR;
			buffer->bytes++;
			return true;
		}
		callback(context, buffer);
	}

	return false;
}

static inline void hal_spi_err_handler(SPI_TypeDef * spi,
	void (*callback)(volatile void *, hal_error_t),
	volatile void * context) {
	if (spi && callback && (spi->CR2 & SPI_CR2_ERRIE)) {
		if (spi->SR & SPI_SR_MODF) {
			callback(context, HAL_ERR_SPI_MODF);
		}

		if (spi->SR & SPI_SR_OVR) {
			callback(context, HAL_ERR_SPI_OVR);
		}

		if (spi->SR & SPI_SR_FRE) {
			callback(context, HAL_ERR_SPI_FRE);
		}

		if (spi->SR & SPI_SR_UDR) {
			callback(context, HAL_ERR_SPI_UDR);
		}

		if (spi->SR & SPI_SR_CRCERR) {
			callback(context, HAL_ERR_SPI_CRCERR);
		}
	}
}

void hal_spi_irq_handler(volatile hal_spi_dsc_t * context) {
	if (context && NVIC_GetPendingIRQ(context->irqn)) {
		_Bool tx_status = hal_spi_irq_tx_handler(context->spi,
			context->tx_buffer, context->transfer_complete, context->arg);
		_Bool rx_status = hal_spi_irq_rx_handler(context->spi,
			context->rx_buffer, context->on_received, context->arg);
		hal_spi_err_handler(context->spi,
			context->err_handler, context->arg);
	}
}
#endif
