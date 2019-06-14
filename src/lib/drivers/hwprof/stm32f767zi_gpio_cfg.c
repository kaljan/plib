#include "hwprof.h"

hal_gpio_t led2_pb7 = {
	.pin = 7,
	.value = false,
	.type = DIGITAL_OUT,
	.otype = PUSH_PULL,
	.af = 0,
	.gpio = GPIOB
};

hal_gpio_t led3_pb14 = {
	.pin = 14,
	.value = false,
	.type = DIGITAL_OUT,
	.otype = PUSH_PULL,
	.af = 0,
	.gpio = GPIOB
};

hal_gpio_t user_button_pc13 = {
	.pin = 13,
	.value = true,
	.type = DIGITAL_IN,
	.otype = PUSH_PULL,
	.af = 0,
	.gpio = GPIOC
};

hal_gpio_t spi6_miso = {
	.pin = 6,
	.value = true,
	.type = ALTERNATE,
	.otype = PUSH_PULL,
	.af = 8,
	.gpio = GPIOA,
};

hal_gpio_t spi6_mosi = {
	.pin = 5,
	.value = true,
	.type = ALTERNATE,
	.otype = PUSH_PULL,
	.af = 8,
	.gpio = GPIOB,
};

hal_gpio_t spi6_sck = {
	.pin = 5,
	.value = true,
	.type = ALTERNATE,
	.otype = PUSH_PULL,
	.af = 8,
	.gpio = GPIOA,
};

hal_gpio_t sh1106_cs = {
	.pin = 14,
	.value = true,
	.type = DIGITAL_OUT,
	.otype = PUSH_PULL,
	.af = 0,
	.gpio = GPIOD,
};

hal_gpio_t sh1106_dc = {
	.pin = 15,
	.value = false,
	.type = DIGITAL_OUT,
	.otype = PUSH_PULL,
	.af = 0,
	.gpio = GPIOD,
};

hal_gpio_t sh1106_reset = {
	.pin = 12,
	.value = true,
	.type = DIGITAL_OUT,
	.otype = PUSH_PULL,
	.af = 0,
	.gpio = GPIOF,
};

hal_gpio_t qencoder_a = {
	.pin = 9,
	.value = true,
	.type = ALTERNATE,
	.otype = PUSH_PULL,
	.af = 1,
	.gpio = GPIOE,
};

hal_gpio_t qencoder_b = {
	.pin = 11,
	.value = true,
	.type = ALTERNATE,
	.otype = PUSH_PULL,
	.af = 1,
	.gpio = GPIOE,
};
