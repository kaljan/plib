#include "hal_rcc.h"

void hal_rcc_spi1_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI1EN;
	}
}

void hal_rcc_spi4_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_SPI4EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI4EN;
	}
}

void hal_rcc_spi5_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_SPI5EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI5EN;
	}
}

void hal_rcc_spi6_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_SPI6EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_SPI6EN;
	}
}

void hal_rcc_tim1_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM1EN;
	}
}

void hal_rcc_tim8_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM8EN;
	}
}

void hal_rcc_tim9_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM9EN;
	}
}

void hal_rcc_tim10_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM10EN;
	}
}

void hal_rcc_tim11_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
	} else {
		RCC->APB2ENR &= ~RCC_APB2ENR_TIM11EN;
	}
}
