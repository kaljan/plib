
#include "hal_tim.h"
#include "hal_rcc.h"

void hal_tim_enable(TIM_TypeDef * tim, _Bool enable) {
	if (tim) {
		if (enable) {
			tim->CR1 |= TIM_CR1_CEN;
			return;
		}
		tim->CR1 &= ~TIM_CR1_CEN;
	}
}

void hal_tim_clear(TIM_TypeDef * tim) {
	if (tim) {
		tim->CNT = 0;
	}
}

void hal_tim_setc(TIM_TypeDef * tim, uint32_t c) {
	if (tim) {
		tim->CNT = c;
	}
}


void hal_tim_set_prescaller(TIM_TypeDef * tim, uint32_t psc) {
	if (tim) {
		tim->PSC = psc;
	}
}

void hal_tim_set_value(TIM_TypeDef * tim, uint32_t arr) {
	if (tim) {
		tim->ARR = arr;
	}
}

void hal_tim_uie(TIM_TypeDef * tim, _Bool enable) {
	if (tim) {
		if (enable) {
			tim->DIER |= TIM_DIER_UIE;
			return;
		}
		tim->DIER &= ~TIM_DIER_UIE;
	}
}

void hal_tim_ug(TIM_TypeDef * tim) {
	if (tim) {
		tim->EGR |= TIM_EGR_UG;
		while (!(tim->SR & TIM_SR_UIF));
		tim->SR &= ~TIM_SR_UIF;
	}
}

void hal_tim_irq_handler(hal_tim_t * timer) {
	if (timer && timer->tim &&
		(timer->tim->DIER & TIM_DIER_UIE) &&
		(timer->tim->SR & TIM_SR_UIF)) {
		timer->tim->SR &= ~TIM_SR_UIF;
		if (timer->callback && !timer->callback(timer->context)) {
			timer->busy = false;
			hal_tim_uie(timer->tim, false);
			hal_tim_enable(timer->tim, false);
			NVIC_DisableIRQ(timer->irqn);
		}
	}
}

int hal_tim_run_delay(hal_tim_t * timer, int delay_us,
	_Bool (*callback)(volatile void *), volatile void * arg) {
	int ret = -1;
	if (timer) {
		ret = 1;
		if (!timer->busy) {
			timer->busy = true;
			ret = 0;
			if (!timer->initialized) {
				timer->callback = callback;
				timer->context = arg;

				if (timer->rcc_clk_enable) {
					timer->rcc_clk_enable(true);
				}
				hal_tim_set_prescaller(timer->tim, timer->psc);
				timer->initialized = true;
			}

			timer->arr = (uint32_t)delay_us;
			hal_tim_clear(timer->tim);
			hal_tim_set_value(timer->tim, timer->arr);
			hal_tim_ug(timer->tim);
			hal_tim_uie(timer->tim, true);
			NVIC_EnableIRQ(timer->irqn);
			hal_tim_enable(timer->tim, true);
		}
	}
	return ret;
}
