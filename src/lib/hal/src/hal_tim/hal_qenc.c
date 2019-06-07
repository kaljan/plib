/**
 * @file 	hal_qenc.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 7, 2019
 *
 * @brief
 */

#include "hal_qenc.h"

void hal_qenc_irq_handler(hal_qenc_t * context) {
	if (context) {

	}
}

int hal_qenc_init(hal_qenc_t * context,
	void (*callback)(volatile void *), void * object) {
	int ret = -1;
	if (context) {

	}
	return ret;
}
#if 0
static volatile uint16_t encoder_value;
static volatile uint16_t ccr1;
static volatile uint16_t ccr2;
static irq_callback_t TIM1_Callback;


/**
 *
 */
void TIM1_CC_IRQHandler(void) {
	GPIOA->BSRR |= GPIO_BSRR_BS_3;
	if ((TIM1->SR & TIM_SR_CC1IF) || (TIM1->SR & TIM_SR_CC2IF)) {
		ccr1 = TIM1->CCR1;
		ccr2 = TIM1->CCR2;
		encoder_value = TIM1->CNT;

		if (TIM1_Callback != NULL) {
			(*TIM1_Callback)();
		}
	}
	GPIOA->BSRR |= GPIO_BSRR_BR_3;
}

/**
 *
 * @return
 */
uint16_t get_encoder_value(void) {
	return encoder_value;
}

/**
 *
 * @return
 */
uint16_t get_encoder_ccr1(void) {
	return ccr1;
}

/**
 *
 * @return
 */
uint16_t get_encoder_ccr2(void) {
	return ccr2;
}

/**
 * ENC_A: PE9, CH1
 * ENC_B: PE11, CH2
 */
void TIM1_EncModeInit(irq_callback_t callback) {

	encoder_value = 0;
	TIM1_Callback = callback;

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	TIM1->SMCR |=
		TIM_SMCR_SMS_0 |
		TIM_SMCR_SMS_1;

	TIM1->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_1;

	TIM1->CCER |=
		TIM_CCER_CC1E |
		TIM_CCER_CC2E;

	TIM1->DIER |=
		TIM_DIER_CC1IE |
		TIM_DIER_CC2IE;

	TIM1->CR1 |= TIM_CR1_ARPE;

	NVIC_EnableIRQ(TIM1_CC_IRQn);

	TIM1->CR1 |= TIM_CR1_CEN;

}
#endif
