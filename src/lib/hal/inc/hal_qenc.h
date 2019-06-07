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

typedef struct _hal_qenc_t {
	_Bool initialized;
	uint16_t ccr1_value;
	uint16_t ccr2_value;
	uint16_t encoder_value;
	TIM_TypeDef * tim;
	IRQn_Type irqn;
	hal_gpio_t * term_a;
	hal_gpio_t * term_b;
	void (*callback)(volatile void *);
	volatile void * object;
} hal_qenc_t;

#endif // HAL_QENC_H
