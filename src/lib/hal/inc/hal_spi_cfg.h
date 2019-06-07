#ifndef HAL_SPI_CFG_H
#define HAL_SPI_CFG_H

#include "hal.h"

typedef enum {
	BR_FPCLR_2 = 0x00,
	BR_FPCLR_4 = 0x01,
	BR_FPCLR_8 = 0x02,
	BR_FPCLR_16 = 0x03,
	BR_FPCLR_32 = 0x04,
	BR_FPCLR_64 = 0x05,
	BR_FPCLR_128 = 0x06,
	BR_FPCLR_256 = 0x07
} hal_spi_baudrate_t;

typedef enum {
	DS_4_BITS = 0x03,
	DS_5_BITS = 0x04,
	DS_6_BITS = 0x05,
	DS_7_BITS = 0x06,
	DS_8_BITS = 0x07,
	DS_9_BITS = 0x08,
	DS_10_BITS = 0x09,
	DS_11_BITS = 0x0A,
	DS_12_BITS = 0x0B,
	DS_13_BITS = 0x0C,
	DS_14_BITS = 0x0D,
	DS_15_BITS = 0x0E,
	DS_16_BITS = 0x0F
} hal_spi_data_size_t;

typedef enum {
	FIFO_EMPTY = 0x00,
	FIFO_1_4_FULL = 0x01,
	FIFO_1_2_FULL = 0x02,
	FIFO_FULL = 0x03
} hal_spi_fifo_status_t;

typedef struct _hal_spi_cfg_t {
	_Bool master;
	_Bool cpol;
	_Bool cpha;
	_Bool lsb_first;
	hal_spi_data_size_t datasize;
	hal_spi_baudrate_t baudrate;
	_Bool soft_slave_mgmt;
	_Bool internal_slave_select;
	_Bool rx_enabled;
	_Bool tx_enabled;
} hal_spi_cfg_t;

void hal_spi_set_bidirect_mode(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_direction(SPI_TypeDef * spi, direction_t direction);
void hal_spi_set_rx_only(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_ssm(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_ssi(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_lsb_first(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_enable(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_baud(SPI_TypeDef * spi, hal_spi_baudrate_t baudrate);
void hal_spi_set_master(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_cpol(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_cpha(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_set_data_size(SPI_TypeDef * spi, hal_spi_data_size_t size);
void hal_spi_txe_irq_enable(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_rxne_irq_enable(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_err_irq_enable(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_tx_dma_enable(SPI_TypeDef * spi, _Bool enabled);
void hal_spi_rx_dma_enable(SPI_TypeDef * spi, _Bool enabled);
_Bool hal_spi_set_config(SPI_TypeDef * context, hal_spi_cfg_t * config);

#endif /* HAL_SPI_CFG_H */
