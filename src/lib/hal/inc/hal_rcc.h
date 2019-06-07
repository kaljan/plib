#ifndef HAL_RCC_H
#define HAL_RCC_H

#include "hal.h"

void hal_rcc_gpioa_enable(_Bool enabled);
void hal_rcc_gpiob_enable(_Bool enabled);
void hal_rcc_gpioc_enable(_Bool enabled);
void hal_rcc_gpiod_enable(_Bool enabled);
void hal_rcc_gpioe_enable(_Bool enabled);
void hal_rcc_gpiof_enable(_Bool enabled);
void hal_rcc_gpiog_enable(_Bool enabled);
void hal_rcc_gpioh_enable(_Bool enabled);

void hal_rcc_tim1_enable(_Bool enabled);
void hal_rcc_tim2_enable(_Bool enabled);
void hal_rcc_tim3_enable(_Bool enabled);
void hal_rcc_tim4_enable(_Bool enabled);
void hal_rcc_tim5_enable(_Bool enabled);
void hal_rcc_tim6_enable(_Bool enabled);
void hal_rcc_tim7_enable(_Bool enabled);
void hal_rcc_tim8_enable(_Bool enabled);
void hal_rcc_tim9_enable(_Bool enabled);
void hal_rcc_tim10_enable(_Bool enabled);
void hal_rcc_tim11_enable(_Bool enabled);
void hal_rcc_tim12_enable(_Bool enabled);
void hal_rcc_tim13_enable(_Bool enabled);
void hal_rcc_tim14_enable(_Bool enabled);

void hal_rcc_dma1_enable(_Bool enabled);
void hal_rcc_dma2_enable(_Bool enabled);

void hal_rcc_spi1_enable(_Bool enabled);
void hal_rcc_spi2_enable(_Bool enabled);
void hal_rcc_spi3_enable(_Bool enabled);
void hal_rcc_spi4_enable(_Bool enabled);
void hal_rcc_spi5_enable(_Bool enabled);
void hal_rcc_spi6_enable(_Bool enabled);

#endif // HAL_RCC_H
