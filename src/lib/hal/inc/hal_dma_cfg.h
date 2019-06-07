/**
 * @file 	hal_dma_cfg.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef HAL_DMA_CFG_H
#define HAL_DMA_CFG_H

#include "hal.h"

typedef enum {
	WIDTH_8BITS = 0x00,
	WIDTH_16BITS = 0x01,
	WIDTH_32BITS = 0x02,
} hal_dma_bus_width_t;

typedef enum {
	DIR_PRERIPH_TO_MEM = 0x00,
	DIR_MEM_TO_PRERIPH = 0x01,
	DIR_MEM_TO_MEM = 0x02
} hal_dma_direction_t;

typedef struct _hal_dma_cfg_t {
	uint8_t channel;
	_Bool memory_increment;
	_Bool periph_increment;
	uint8_t priority;
	hal_dma_bus_width_t bus_width;
	hal_dma_direction_t direction;
	_Bool pfctl;
	_Bool tcie;
	_Bool teie;
	_Bool dmeie;
	uint32_t periph_addr;
} hal_dma_cfg_t;


void hal_dma_set_channel(DMA_Stream_TypeDef * dma_stream, uint8_t channel);
void hal_dma_set_priority(DMA_Stream_TypeDef * dma_stream, uint8_t level);
void hal_dma_set_bus_width(DMA_Stream_TypeDef * dma_stream,
	hal_dma_bus_width_t width);
void hal_dma_set_minc(DMA_Stream_TypeDef * dma_stream, _Bool enabled);
void hal_dma_set_pinc(DMA_Stream_TypeDef * dma_stream, _Bool enabled);
void hal_dma_set_direction(DMA_Stream_TypeDef * dma_stream,
	hal_dma_direction_t direction);
void hal_dma_set_pfctl(DMA_Stream_TypeDef * dma_stream, _Bool pfctl);
void hal_dma_set_tcie(DMA_Stream_TypeDef * dma_stream, _Bool enabled);
_Bool hal_dma_get_tcie(DMA_Stream_TypeDef * stream);
void hal_dma_set_teie(DMA_Stream_TypeDef * dma_stream, _Bool enabled);
_Bool hal_dma_get_teie(DMA_Stream_TypeDef * stream);
void hal_dma_set_dmeie(DMA_Stream_TypeDef * dma_stream, _Bool enabled);
_Bool hal_dma_get_dmeie(DMA_Stream_TypeDef * stream);
void hal_dma_stream_enable(DMA_Stream_TypeDef * dma_stream, _Bool enabled);
_Bool hal_dma_stream_enabled(DMA_Stream_TypeDef * dma_stream);
void hal_dma_set_data_size(DMA_Stream_TypeDef * dma_stream, size_t size);
void hal_dma_set_mem_addr(DMA_Stream_TypeDef * dma_stream, uint32_t address);
void hal_dma_set_pf_addr(DMA_Stream_TypeDef * dma_stream, uint32_t address);

_Bool hal_dma_set_config(DMA_Stream_TypeDef * instance, hal_dma_cfg_t * config);

#endif // HAL_DMA_CFG_H
