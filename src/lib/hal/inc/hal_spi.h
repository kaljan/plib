#ifndef HAL_SPI_H
#define HAL_SPI_H

#include "buffer.h"

#include "hal_gpio.h"
#include "hal_dma.h"
#include "hal_irq.h"
#include "hal_spi_cfg.h"

#define HAL_SPI6	0

typedef struct _hal_spi_dsc_t {
	int id;
	_Bool busy;
	hal_spi_cfg_t * spi_cfg; // если конфиг NULL -- интерфейс свободен
	SPI_TypeDef * spi;
	IRQn_Type irqn;

	hal_dma_cfg_t * tx_dma_config;
	hal_dma_dsc_t * tx_dma_dsc;
	buffer_t * tx_buffer;

	hal_dma_cfg_t * rx_dma_config;
	hal_dma_dsc_t * rx_dma_dsc;
	buffer_t * rx_buffer;

	hal_gpio_t * mosi;
	hal_gpio_t * miso;
	hal_gpio_t * sck;

	void (*rcc_clk_enable)(_Bool);
	void (*transfer_complete)(volatile void *);
	void (*on_received)(volatile void *, buffer_t *);
	void (*err_handler)(volatile void *, hal_error_t);
	volatile void * arg;
} hal_spi_dsc_t;

hal_spi_dsc_t * hal_spi_get_context(int id);
int hal_spi_connect(hal_spi_dsc_t * dsc, hal_interface_t * handler);
void hal_spi_disconnect(hal_spi_dsc_t * dsc);
int hal_spi_transfer(hal_spi_dsc_t * context, void * data, size_t size);

void hal_spi_tx_dma_handler(volatile void * arg);
void hal_spi_tx_dma_te_handler(volatile void *arg);
void hal_spi_tx_dma_dme_handler(volatile void *arg);
void hal_spi_rx_dma_handler(volatile void * arg);
void hal_spi_irq_handler(volatile hal_spi_dsc_t * context);

#endif /* HAL_SPI_H */

