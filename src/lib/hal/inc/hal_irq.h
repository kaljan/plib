#ifndef HAL_INTERRUPTS
#define HAL_INTERRUPTS

#include "hal.h"

typedef struct _hal_irq_handler_t {
	void (*callback)(void *);
	void * object;
} hal_irq_handler_t;

void hal_irq_handle(hal_irq_handler_t * context);

#endif // HAL_INTERRUPTS
