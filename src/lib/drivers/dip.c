#include "dip.h"
#include "dlist.h"

#define DEBOUNCE_MAX	512
#define DEBOUNCE_INIT	0
#define DEBOUNCE_MIN	-512

// digital input pin list
static d_node_t * di_head = NULL;
static d_node_t * di_tail = NULL;

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

void di_poll_add(hal_gpio_t * pin,
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

//typedef struct _hal_di_event_t {
//	hal_gpio_t * pin;
//	event_callback_t callback;
//	_Bool prev_value;
//} dip_event_t;
//
//void dip_add(GPIO_TypeDef * gpio, int pin, event_callback_t callback);
//void dip_poll(void);

//static dip_event_t * create_event(hal_gpio_t * pin, event_callback_t callback) {
//	dip_event_t * event = NULL;
//	if (pin && (event = malloc(sizeof(dip_event_t)))) {
//		event->pin = pin;
//		event->callback = callback;
//	}
//	return event;
//}
//void dip_add(GPIO_TypeDef * gpio, int pin, event_callback_t callback) {
//	hal_gpio_t * instance = create_instance(gpio, pin);
//	dip_event_t * event = create_event(instance, callback);
//
//	hal_gpio_init(instance);
//	push_back(&di_tail, (void *)event);
//
//	if (!di_tail) {
//		if (instance) {
//			free(instance);
//		}
//		if (event) {
//			free(event);
//		}
//	}
//	if (!di_head) {
//		di_head = di_tail;
//	}
//}
//
//void dip_poll(void) {
//	if (di_head) {
//		d_node_t * curr = di_head;
//		while (curr) {
//			dip_event_t * event = (dip_event_t *)curr->object;
//			if (event && event->callback) {
//				_Bool value = hal_gpio_get_debounce_value(
//					event->pin->gpio, event->pin->pin);
//				if (value != event->prev_value) {
//					event->prev_value = value;
//					if (value == true) {
//						event->callback(RISING);
//					} else {
//						event->callback(FALLING);
//					}
//				}
//			}
//		}
//		curr = curr->next;
//	}
//}

//		while (curr) {
//			dip_event_t * event = (dip_event_t *)curr->object;
//			if (event && event->callback) {
//				_Bool value = hal_gpio_get_debounce_value(
//					event->pin->gpio, event->pin->pin);
//				if (value != event->prev_value) {
//					event->prev_value = value;
//					if (value == true) {
//						event->callback(RISING);
//					} else {
//						event->callback(FALLING);
//					}
//				}
//			}
//		}
//		curr = curr->next;

//void hal_gpio_add_di(hal_gpio_t * pin, event_callback_t callback);
//void hal_gpio_add_di(hal_gpio_t * pin, event_callback_t callback) {
//	hal_di_event_t * event = create_event(pin, callback);
//	push_back(&di_tail, (void *)event);
//
//	if (!di_tail && event) {
//		free(event);
//	}
//	if (!di_head) {
//		di_head = di_tail;
//	}
//}
