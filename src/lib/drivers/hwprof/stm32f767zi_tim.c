#include "hwprof.h"

hal_tim_t tim7_delay = {
	.id = TIM7_DELAY_ID,
	.busy = false,
	.psc = 107,
	.arr = 0,
	.tim = TIM7,
	.irqn = TIM7_IRQn,
	.rcc_clk_enable = hal_rcc_tim7_enable,
	.callback = NULL,
	.context = NULL,
};

hal_tim_t *tim_list[] = {
	&tim7_delay, NULL
};

hal_tim_t * hal_tim_get_context(int id) {
	hal_tim_t ** list = tim_list;
	while (*list) {
		if ((*list)->id == id) {
			if ((*list)->busy) {
				break;
			}
			return *list;
		}
	}
	return NULL;
}

void TIM7_IRQHandler(void) {
	hal_tim_irq_handler(&tim7_delay);
}
