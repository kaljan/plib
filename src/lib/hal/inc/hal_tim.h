#ifndef HAL_TIM_H
#define HAL_TIM_H

#include "hal.h"

#define TIM7_DELAY_ID	0

typedef struct _hal_tim_t {
	int id;
	_Bool busy;
	_Bool initialized;
	uint32_t psc;
	uint32_t arr;
	TIM_TypeDef * tim;
	IRQn_Type irqn;
	void (*rcc_clk_enable)(_Bool);
	_Bool (*callback)(volatile void *);
	volatile void * context;
} hal_tim_t;

void hal_tim_set_singleshot(TIM_TypeDef * tim, _Bool singleshot);
void hal_tim_enable(TIM_TypeDef * tim, _Bool enable);
void hal_tim_set_prescaller(TIM_TypeDef * tim, uint32_t psc);
void hal_tim_set_value(TIM_TypeDef * tim, uint32_t arr);
void hal_tim_uie(TIM_TypeDef * tim, _Bool enable);

hal_tim_t * hal_tim_get_context(int id);
void hal_tim_irq_handler(hal_tim_t * timer);
int hal_tim_run_delay(hal_tim_t * timer, int delay_us,
	_Bool (*callback)(volatile void *), volatile void * arg);

#endif // HAL_TIM_H
