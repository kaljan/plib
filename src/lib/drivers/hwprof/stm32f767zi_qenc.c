/**
 * @file 	stm32f767zi_qenc.c
 * @author	kaljan
 * @version	0.0.0
 * @date	Jun 13, 2019
 *
 * @brief
 */


#include "hwprof.h"

hal_qenc_t qencoder = {
	.initialized = false,
	.ccr1_value = 0,
	.ccr2_value = 0,
	.encoder_value = 0,
	.delta = 0,
	.tim = TIM1,
	.irqn = TIM1_CC_IRQn,
	.term_a = &qencoder_a,
	.term_b = &qencoder_b,
	.rcc_clk_enable = hal_rcc_tim1_enable,
	.callback = NULL,
	.object = NULL,
};

void TIM1_CC_IRQHandler(void) {
	hal_qenc_irq_handler(&qencoder);
}
