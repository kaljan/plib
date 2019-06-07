#ifndef HWPROF_HWPROF_H
#define HWPROF_HWPROF_H

#include "hal.h"

#include "hal_spi.h"
#include "hal_dma.h"
#include "hal_rcc.h"
#include "hal_tim.h"

extern hal_gpio_t led2_pb7;
extern hal_gpio_t led3_pb14;
extern hal_gpio_t user_button_pc13;
extern hal_gpio_t spi6_miso;
extern hal_gpio_t spi6_mosi;
extern hal_gpio_t spi6_sck;
extern hal_gpio_t sh1106_cs;
extern hal_gpio_t sh1106_dc;
extern hal_gpio_t sh1106_reset;

extern hal_tim_t tim7_delay;
extern hal_tim_t *tim_list[];

extern hal_dma_cfg_t dma2_stream5_cfg;
extern hal_dma_dsc_t dma2_stream5_dsc;
extern hal_dma_dsc_t dma2_stream6_dsc;
extern hal_dma_cfg_t dma2_stream6_cfg;

extern hal_spi_dsc_t spi6_dsc;
extern hal_spi_dsc_t * spi_list[];
//extern hal_if_t spi6_interface;

#endif // HWPROF_HWPROF_H
