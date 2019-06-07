#include "hal_dma_cfg.h"

void hal_dma_set_channel(DMA_Stream_TypeDef * dma_stream,
	uint8_t channel) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		dma_stream->CR |= (channel & 0x0F) << 25;
	}
}

void hal_dma_set_priority(DMA_Stream_TypeDef * dma_stream, uint8_t level) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		dma_stream->CR |= (level & 0x03) << 23;
	}
}

void hal_dma_set_bus_width(DMA_Stream_TypeDef * dma_stream,
	hal_dma_bus_width_t width) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		dma_stream->CR |= ((width & 0x03) << 13) |
			((width & 0x03) << 11);
	}
}

hal_dma_bus_width_t hal_dma_get_bus_width(DMA_Stream_TypeDef * dma_stream) {
	if (dma_stream) {
		return (hal_dma_bus_width_t)((dma_stream->CR & DMA_SxCR_PSIZE) >> 11);
	}
	return WIDTH_8BITS;
}

void hal_dma_set_minc(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_MINC;
		} else {
			dma_stream->CR &= ~DMA_SxCR_MINC;
		}
	}
}

void hal_dma_set_pinc(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_PINC;
		} else {
			dma_stream->CR &= ~DMA_SxCR_PINC;
		}
	}
}

void hal_dma_enable_circ(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_CIRC;
		} else {
			dma_stream->CR &= ~DMA_SxCR_CIRC;
		}
	}
}

void hal_dma_set_direction(DMA_Stream_TypeDef * dma_stream,
	hal_dma_direction_t direction) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		dma_stream->CR |= (direction & 0x03) << 6;
	}
}

void hal_dma_set_pfctl(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_PFCTRL;
		} else {
			dma_stream->CR &= ~DMA_SxCR_PFCTRL;
		}
	}
}

void hal_dma_set_tcie(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_TCIE;
		} else {
			dma_stream->CR &= ~DMA_SxCR_TCIE;
		}
	}
}
_Bool hal_dma_get_tcie(DMA_Stream_TypeDef * stream) {
	if (stream) {
		if (stream->CR & DMA_SxCR_TCIE) {
			return true;
		}
	}
	return false;
}

void hal_dma_set_teie(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_TEIE;
		} else {
			dma_stream->CR &= ~DMA_SxCR_TEIE;
		}
	}
}

_Bool hal_dma_get_teie(DMA_Stream_TypeDef * stream) {
	if (stream) {
		if (stream->CR & DMA_SxCR_TEIE) {
			return true;
		}
	}
	return false;
}

void hal_dma_set_dmeie(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_DMEIE;
		} else {
			dma_stream->CR &= ~DMA_SxCR_DMEIE;
		}
	}
}

_Bool hal_dma_get_dmeie(DMA_Stream_TypeDef * stream) {
	if (stream) {
		if (stream->CR & DMA_SxCR_DMEIE) {
			return true;
		}
	}
	return false;
}

void hal_dma_stream_enable(DMA_Stream_TypeDef * dma_stream, _Bool enabled) {
	if (dma_stream) {
		if (enabled) {
			dma_stream->CR |= DMA_SxCR_EN;
		} else {
			dma_stream->CR &= ~DMA_SxCR_EN;
		}
	}
}

_Bool hal_dma_stream_enabled(DMA_Stream_TypeDef * dma_stream) {
	if (dma_stream && (dma_stream->CR & DMA_SxCR_EN)) {
		return true;
	}
	return false;
}

void hal_dma_set_data_size(DMA_Stream_TypeDef * dma_stream, size_t size) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		hal_dma_bus_width_t width = hal_dma_get_bus_width(dma_stream);
		size >>= width;
		dma_stream->NDTR = size;
	}
}

void hal_dma_set_mem_addr(DMA_Stream_TypeDef * dma_stream, uint32_t address) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		dma_stream->M0AR = address;
	}
}

void hal_dma_set_pf_addr(DMA_Stream_TypeDef * dma_stream, uint32_t address) {
	if (dma_stream && !(dma_stream->CR  & DMA_SxCR_EN)) {
		dma_stream->PAR = address;
	}
}

_Bool hal_dma_set_config(DMA_Stream_TypeDef * stream, hal_dma_cfg_t * config) {
	if (config && stream) {
		hal_dma_set_channel(stream, config->channel);
		hal_dma_set_priority(stream, config->priority);
		hal_dma_set_bus_width(stream, config->bus_width);
		hal_dma_set_minc(stream, config->memory_increment);
		hal_dma_set_pinc(stream, config->periph_increment);
		hal_dma_set_direction(stream, config->direction);
		hal_dma_set_pfctl(stream, config->pfctl);
		hal_dma_set_tcie(stream, config->tcie);
		hal_dma_set_teie(stream, config->teie);
		hal_dma_set_dmeie(stream, config->dmeie);
		hal_dma_set_pf_addr(stream, config->periph_addr);
		return true;
	}
	return false;
}
