/**
 * @file 	hal_qenc.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 7, 2019
 *
 * @brief	Quadrature encoder driver
 */

#include "hal_qenc.h"

/**
 * Interrupt handler
 *
 * @param context	encoder
 */
void hal_qenc_irq_handler(hal_qenc_t * context) {
	if (context) {
		if ((context->tim->SR & TIM_SR_CC1IF) || (context->tim->SR & TIM_SR_CC2IF)) {
			context->ccr1_value = context->tim->CCR1;
			context->ccr2_value = context->tim->CCR2;
			context->encoder_value = context->tim->CNT;

			if ((context->ccr1_value == 0) && (context->encoder_value == 65535)) {
				context->delta = -1;
			} else {
				context->delta = (int) (
					(int)context->encoder_value -
					(int)context->ccr1_value);
			}

			if (context->callback) {
				context->callback(context->object, context->delta);
			}
		}
	}
}

/**
 *
 * @param tim
 */
void hal_qenc_mode_set(TIM_TypeDef * tim) {
	if (tim) {
		tim->SMCR |=
			TIM_SMCR_SMS_0 |
			TIM_SMCR_SMS_1;

		tim->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_1;

		tim->CCER |=
			TIM_CCER_CC1E |
			TIM_CCER_CC2E;

		tim->DIER |=
			TIM_DIER_CC1IE |
			TIM_DIER_CC2IE;

		tim->CR1 |= TIM_CR1_ARPE;
	}
}

/**
 *
 * @param context
 * @param callback
 * @param object
 * @return
 */
int hal_qenc_init(hal_qenc_t * context,
	void (*callback)(volatile void *, int), volatile void * object) {
	int ret = -1;
	if (context) {
		if (context->initialized) {
			ret = 1;
			return ret;
		}
		if (context->rcc_clk_enable) {
			context->rcc_clk_enable(true);
		}
		hal_gpio_init(context->term_a);
		hal_gpio_init(context->term_b);
		hal_qenc_mode_set(context->tim);
		NVIC_EnableIRQ(context->irqn);
		hal_tim_enable(context->tim, true);
		context->callback = callback;
		context->object = object;
		context->initialized = true;
		ret = 0;
	}
	return ret;
}
