#include "hwprof.h"

hal_spi_dsc_t spi6_dsc = {
	.id = HAL_SPI6,
	.busy = false,
	.spi_cfg = NULL,
	.spi = SPI6,
	.irqn = SPI6_IRQn,
	.tx_dma_config = &dma2_stream5_cfg,
	.tx_dma_dsc = &dma2_stream5_dsc,
	.tx_buffer = NULL,
	.rx_dma_config = &dma2_stream6_cfg,
	.rx_dma_dsc = &dma2_stream6_dsc,
	.rx_buffer = NULL,
	.mosi = &spi6_mosi,
	.miso = &spi6_miso,
	.sck = &spi6_sck,
	.rcc_clk_enable = hal_rcc_spi6_enable,
	.transfer_complete = NULL,
	.on_received = NULL,
	.err_handler = NULL,
	.arg = NULL,
};

hal_spi_dsc_t * spi_list[] = {
	&spi6_dsc, NULL
};

//hal_if_t spi6_interface = {
//	.id = HAL_IF_SPI6_ID,
//	.connected = false,
//	.descriptor = &spi6_dsc,
//	.get_status = hal_spi_get_status,
//	.connect = hal_spi_connect,
//	.disconnect = hal_spi_disconnect,
//	.transfer = hal_spi_transfer,
//};
