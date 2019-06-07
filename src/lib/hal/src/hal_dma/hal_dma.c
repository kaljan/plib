#include "hal_dma.h"

int hal_dma_configure(hal_dma_dsc_t * context, hal_dma_cfg_t * config) {
	int ret = -1;
	if (context && !context->initialized && config) {
		ret = 0;
		if (context->rcc_clk_enable) {
			context->rcc_clk_enable(true);
		}
		hal_dma_set_config(context->stream, config);

		if (config->tcie || config->teie || config->dmeie) {
			NVIC_EnableIRQ(context->irqn);
		} else {
			NVIC_DisableIRQ(context->irqn);
		}
		context->initialized = true;
	}
	return ret;
}

void clear_all_flags(DMA_TypeDef * dma, int stream) {
	if (dma) {
		volatile uint32_t * reg = &dma->LIFCR;
		if (stream > 3) {
			reg = &dma->HIFCR;
		}
		*reg |= (DMA_LIFCR_CFEIF0 | DMA_LIFCR_CDMEIF0 | DMA_LIFCR_CTEIF0 |
			DMA_LIFCR_CHTIF0 | DMA_LIFCR_CTCIF0) <<
				(((stream & 0x01) << 4) + ((stream & 0x02) << 3));
	}
}

int hal_dma_transfer(hal_dma_dsc_t * instance, void * data, size_t size) {
	int ret = -1;
	if (instance && instance->stream && data &&
		!hal_dma_stream_enabled(instance->stream)) {
		hal_dma_set_data_size(instance->stream, size);
		hal_dma_set_mem_addr(instance->stream, (uint32_t)data);
		clear_all_flags(instance->dma, instance->n_stream);
		hal_dma_stream_enable(instance->stream, true);
		return 0;
	}
	return ret;
}

static inline void hal_dma_set_ifcr(DMA_TypeDef * dma, int stream, uint32_t mask) {
	if (dma) {
		volatile uint32_t * reg = &dma->LIFCR;
		if (stream > 3) {
			reg = &dma->HIFCR;
		}
		*reg = mask << (((stream & 0x01) * 6) | ((stream & 0x02) << 4));
	}
}

static inline _Bool hal_dma_get_ifsr(DMA_TypeDef * dma, int stream, uint32_t mask) {
	if (dma) {
		volatile uint32_t * reg = &dma->LISR;
		if (stream > 3) {
			reg = &dma->HISR;
		}
		if (*reg & (mask << (((stream & 0x01) * 5) | ((stream & 0x02) << 3)))) {
			return true;
		}
	}
	return false;
}

static inline _Bool hal_dma_get_tc_status(DMA_TypeDef * dma, DMA_Stream_TypeDef * stream, int n) {
	if (hal_dma_get_tcie(stream)) {
		return hal_dma_get_ifsr(dma, n, DMA_LISR_TCIF0);
	}
	return false;
}

static inline _Bool hal_dma_get_te_status(DMA_TypeDef * dma, DMA_Stream_TypeDef * stream, int n) {
	if (hal_dma_get_teie(stream)) {
		return hal_dma_get_ifsr(dma, n, DMA_LISR_TEIF0);
	}
	return false;
}

static inline _Bool hal_dma_get_dme_status(DMA_TypeDef * dma, DMA_Stream_TypeDef * stream, int n) {
	if (hal_dma_get_dmeie(stream)) {
		return hal_dma_get_ifsr(dma, n, DMA_LISR_DMEIF0);
	}
	return false;
}

void hal_dma_irq_handler(hal_dma_dsc_t * instance) {
	if (instance && instance->stream) {

		if (instance->tc_handler &&
			hal_dma_get_tc_status(instance->dma, instance->stream, instance->n_stream)) {
			hal_dma_set_ifcr(instance->dma, instance->n_stream,
				DMA_LIFCR_CTCIF0 | DMA_LIFCR_CHTIF0);
			instance->tc_handler(instance->context);
		}
		if (instance->te_handler &&
			hal_dma_get_te_status(instance->dma, instance->stream, instance->n_stream)) {
			hal_dma_set_ifcr(instance->dma, instance->n_stream, DMA_LIFCR_CTEIF0);
			instance->te_handler(instance->context);
		}
		if (instance->dme_handler &&
			hal_dma_get_dme_status(instance->dma, instance->stream, instance->n_stream)) {
			hal_dma_set_ifcr(instance->dma, instance->n_stream, DMA_LIFCR_CDMEIF0);
			instance->dme_handler(instance->context);
		}
	}
}
