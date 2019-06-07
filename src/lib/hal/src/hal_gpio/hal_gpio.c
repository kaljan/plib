#include "hal_gpio.h"
#include "dlist.h"


hal_gpio_t * hal_gpio_create_instance(GPIO_TypeDef * gpio, int pin) {
	hal_gpio_t * instance = NULL;
	if (gpio && (instance = malloc(sizeof(hal_gpio_t)))) {
		instance->pin = pin;
		instance->gpio = gpio;
		instance->af = 0;
		instance->type = DIGITAL_IN;
		instance->otype = PUSH_PULL;
		instance->value = true;
	}
	return instance;
}

void hal_gpio_set_type(GPIO_TypeDef * gpio, int pin, gpio_type_t type) {
	if (gpio) {
		if (type == ANALOG) {
			gpio->MODER |= (0x00000003 << ((pin & 0x0F) * 2));
			return;
		}

		gpio->MODER &= ~((0x00000003 << ((pin & 0x0F) * 2)));

		if (type == DIGITAL_IN) {
			return;
		}

		if (type == DIGITAL_OUT) {
			gpio->MODER |= (0x00000001 << ((pin & 0x0F) * 2));
		} else {
			gpio->MODER |= (0x00000002 << ((pin & 0x0F) * 2));
		}
		gpio->OSPEEDR |= (0x00000003 << ((pin & 0x0F) * 2));
	}
}

void hal_gpio_set_otype(GPIO_TypeDef * gpio, int pin, gpio_otype_t otype) {
	if (gpio) {
		if (otype == PUSH_PULL) {
			gpio->BSRR &= ~(0x0001 << (pin & 0x0F));
		}
		gpio->BSRR |= (0x0001 << (pin & 0x0F));
	}
}

void hal_gpio_set_af(GPIO_TypeDef * gpio, int pin, uint32_t af) {
	if (gpio) {
		gpio->AFR[pin >> 3] |= (af & 0x0F) << ((pin & 0x07) << 2);
	}
}

void hal_gpio_set_value(GPIO_TypeDef * gpio, int pin, _Bool value) {
	if (gpio) {
		uint32_t mask = 1;
		if (value == false) {
			mask = 0x00010000;
		}
		gpio->BSRR |= (mask << (pin & 0x0F));
	}
}

void hal_gpio_toggle_value(GPIO_TypeDef * gpio, int pin) {
	if (gpio) {
		uint32_t mask = 1;
		if (gpio->IDR & (mask << (pin & 0x0F))) {
			mask = 0x00010000;
		}
		gpio->BSRR |= (mask << (pin & 0x0F));
	}
}

_Bool hal_gpio_get_value(GPIO_TypeDef * gpio, int pin) {
	uint32_t mask = 1;
	if (gpio && (gpio->IDR & (mask << (pin & 0x0F)))) {
		return true;
	}
	return false;
}

void hal_gpio_init(hal_gpio_t * instance) {
	if (instance) {
		hal_gpio_set_type(instance->gpio, instance->pin, instance->type);
		hal_gpio_set_otype(instance->gpio, instance->pin, instance->otype);
		hal_gpio_set_af(instance->gpio, instance->pin, instance->af);
		hal_gpio_set_value(instance->gpio, instance->pin, instance->value);
	}
}

void hal_gpio_deinit(hal_gpio_t * instance) {
	if (instance) {
		hal_gpio_set_type(instance->gpio, instance->pin, ANALOG);
		hal_gpio_set_otype(instance->gpio, instance->pin, PUSH_PULL);
		hal_gpio_set_af(instance->gpio, instance->pin, 0);
		hal_gpio_set_value(instance->gpio, instance->pin, false);
	}
}

void hal_gpio_if_set_value(hal_gpio_t * instance, _Bool value) {
	if (instance) {
		hal_gpio_set_value(instance->gpio, instance->pin, value);
	}
}

void hal_gpio_if_toggle_value(hal_gpio_t * instance) {
	if (instance) {
		hal_gpio_toggle_value(instance->gpio, instance->pin);
	}
}

_Bool hal_gpio_if_get_value(hal_gpio_t * instance) {
	if (instance) {
		return hal_gpio_get_value(instance->gpio, instance->pin);
	}
	return false;
}
