/**
 * @file 	hal_qenc.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 7, 2019
 *
 * @brief
 */

#ifndef HAL_QENC_H
#define HAL_QENC_H

#include "hal.h"
#include "hal_gpio.h"
#include "hal_tim.h"

typedef struct _hal_qenc_t {
	_Bool initialized;
	uint16_t ccr1_value;
	uint16_t ccr2_value;
	uint16_t encoder_value;
	int delta;
	TIM_TypeDef * tim;
	IRQn_Type irqn;
	hal_gpio_t * term_a;
	hal_gpio_t * term_b;
	void (*rcc_clk_enable)(_Bool);
	void (*callback)(volatile void *, int);
	volatile void * object;
} hal_qenc_t;

void hal_qenc_irq_handler(hal_qenc_t * context);
int hal_qenc_init(hal_qenc_t * context,
	void (*callback)(volatile void *, int), volatile void * object);
#endif // HAL_QENC_H
