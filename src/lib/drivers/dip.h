#ifndef DI_H
#define DI_H

#include "hal_gpio.h"
#include "hal_rcc.h"

typedef struct _di_event_r {
	hal_gpio_t * pin;
	void *(*callback)(hal_event_t, void *);
	void * context;
	_Bool prev_value;
} di_event_t;

void di_poll_add(hal_gpio_t * pin,
	void *(*callback)(hal_event_t, void *), void *context);
void di_poll_event(void);

#endif // DI_H
