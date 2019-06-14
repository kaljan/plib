#include "di.h"
#include "dlist.h"

#define DEBOUNCE_MAX	512
#define DEBOUNCE_INIT	0
#define DEBOUNCE_MIN	-512

// digital input pin list
static d_node_t * di_head = NULL;
static d_node_t * di_tail = NULL;

static di_event_t * di_poll_create_event(hal_gpio_t * pin,
	void * (*callback)(hal_event_t,void*), void * context) {
	di_event_t * event = NULL;
	if (pin && (event = (di_event_t *)malloc(sizeof(di_event_t)))) {
		event->pin = pin;
		event->callback = callback;
		event->context = context;
	}
	return event;
}

void di_add_event(hal_gpio_t * pin,
	void *(*callback)(hal_event_t, void *), void *context) {
	di_event_t * event = di_poll_create_event(pin, callback, context);

	hal_gpio_init(pin);
	push_back(&di_tail, (void *)event);

	if (!di_tail) {
		if (event) {
			free(event);
		}
	}
	if (!di_head) {
		di_head = di_tail;
	}
}

di_event_t * di_poll_iterator(d_node_t ** item) {
	di_event_t * ret = NULL;
	if (item && *item) {
		ret = (di_event_t *)(*item)->object;
		*item = (d_node_t *)(*item)->next;
	}
	return ret;
}

static _Bool hal_gpio_get_debounce_value(GPIO_TypeDef * gpio, int pin) {
	if (gpio) {
		int debounce_timer = DEBOUNCE_INIT;
		while (debounce_timer > DEBOUNCE_MIN) {
			if (hal_gpio_get_value(gpio, pin) == false) {
				debounce_timer--;
				continue;
			}
			debounce_timer++;
			if (debounce_timer > DEBOUNCE_MAX) {
				return true;
			}
		}
	}
	return false;
}

void di_poll_event(void) {
	if (di_head) {
		d_node_t * curr = di_head;
		di_event_t * evt = di_poll_iterator(&curr);
		while (evt) {
			_Bool value = hal_gpio_get_debounce_value(
				evt->pin->gpio, evt->pin->pin);
			if (value != evt->prev_value) {
				evt->prev_value = value;
				if (value == true) {
					evt->context = evt->callback(RISING, evt->context);
				} else {
					evt->context = evt->callback(FALLING, evt->context);
				}
			}
			evt = di_poll_iterator(&curr);
		}
	}
}
