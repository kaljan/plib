#include "hwprof.h"

hal_dma_cfg_t dma2_stream5_cfg = {
	.channel = 1,
	.memory_increment = true,
	.periph_increment = false,
	.priority = 0,
	.bus_width = WIDTH_8BITS,
	.direction = DIR_MEM_TO_PRERIPH,
	.pfctl = false,
	.tcie = true,
	.teie = false,
	.dmeie = false,
	.periph_addr = SPI6_BASE + 0x0C,
};

hal_dma_dsc_t dma2_stream5_dsc = {
	.n_stream = 5,
	.initialized = false,
	.dma = DMA2,
	.stream = DMA2_Stream5,
	.irqn = DMA2_Stream5_IRQn,
	.rcc_clk_enable = hal_rcc_dma2_enable,
	.tc_handler = hal_spi_tx_dma_handler,
	.te_handler = NULL,
	.dme_handler = NULL,
	.context = &spi6_dsc,
};

hal_dma_cfg_t dma2_stream6_cfg = {
	.channel = 1,
	.memory_increment = false,
	.periph_increment = false,
	.priority = 0,
	.bus_width = WIDTH_8BITS,
	.direction = DIR_PRERIPH_TO_MEM,
	.pfctl = false,
	.tcie = false,
	.teie = false,
	.dmeie = false,
	.periph_addr = SPI6_BASE + 0x0C,
};

hal_dma_dsc_t dma2_stream6_dsc = {
	.n_stream = 6,
	.initialized = false,
	.dma = DMA2,
	.stream = DMA2_Stream6,
	.irqn = DMA2_Stream6_IRQn,
	.rcc_clk_enable = hal_rcc_dma2_enable,
	.tc_handler = hal_spi_tx_dma_handler,
	.te_handler = NULL,
	.dme_handler = NULL,
	.context = NULL,
};

void DMA2_Stream5_IRQHandler(void) {
	hal_dma_irq_handler(&dma2_stream5_dsc);
}

void DMA2_Stream6_IRQHandler(void) {
	hal_dma_irq_handler(&dma2_stream6_dsc);
}
