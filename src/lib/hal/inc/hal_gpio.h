/**
 * @file 	hal_gpio.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "hal.h"

typedef enum _gpio_type_t {
	ANALOG,
	DIGITAL_IN,
	DIGITAL_OUT,
	ALTERNATE
} gpio_type_t;

typedef enum _gpio_otype_t {
	PUSH_PULL,
	OPEN_DRAIN
} gpio_otype_t;

typedef struct _hal_gpio_t {
	int pin;
	_Bool value;
	gpio_type_t type;
	gpio_otype_t otype;
	uint32_t af;
	GPIO_TypeDef * gpio;
} hal_gpio_t;


void hal_gpio_set_type(GPIO_TypeDef * gpio, int pin, gpio_type_t type);
void hal_gpio_set_otype(GPIO_TypeDef * gpio, int pin, gpio_otype_t otype);
void hal_gpio_set_af(GPIO_TypeDef * gpio, int pin, uint32_t af);
void hal_gpio_set_value(GPIO_TypeDef * gpio, int pin, _Bool value);
void hal_gpio_toggle_value(GPIO_TypeDef * gpio, int pin);
_Bool hal_gpio_get_value(GPIO_TypeDef * gpio, int pin);
void hal_gpio_init(hal_gpio_t * instance);
void hal_gpio_deinit(hal_gpio_t * instance);

void hal_gpio_if_set_value(hal_gpio_t * instance, _Bool value);
void hal_gpio_if_toggle_value(hal_gpio_t * instance);
_Bool hal_gpio_if_get_value(hal_gpio_t * instance);

#endif
