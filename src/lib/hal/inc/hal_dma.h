/**
 * @file 	hal_dma.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef HAL_DMA_H
#define HAL_DMA_H

#include "hal_irq.h"
#include "hal_dma_cfg.h"

typedef struct _hal_dma_dsc_t {
	int n_stream;
	_Bool initialized;
	DMA_TypeDef * dma;
	DMA_Stream_TypeDef * stream;
	IRQn_Type irqn;
	void (*rcc_clk_enable)(_Bool);
	void (*tc_handler)(volatile void *);
	void (*te_handler)(volatile void *);
	void (*dme_handler)(volatile void *);
	volatile void * context;
} hal_dma_dsc_t;

int hal_dma_configure(hal_dma_dsc_t * context, hal_dma_cfg_t * config);
int hal_dma_transfer(hal_dma_dsc_t * instance, void * data, size_t size);
void hal_dma_irq_handler(hal_dma_dsc_t * instance);

#endif // HAL_DMA_H
