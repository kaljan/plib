#include "hal_irq.h"

void hal_irq_handle(hal_irq_handler_t * context) {
	if (context && context->callback) {
		context->callback(context->object);
	}
}
