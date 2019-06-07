#include "hal_rcc.h"

void hal_rcc_tim2_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM2EN;
	}
}

void hal_rcc_tim3_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM3EN;
	}
}

void hal_rcc_tim4_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM4EN;
	}
}

void hal_rcc_tim5_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM5EN;
	}
}

void hal_rcc_tim6_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM6EN;
	}
}

void hal_rcc_tim7_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM7EN;
	}
}

void hal_rcc_tim12_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM12EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM12EN;
	}
}

void hal_rcc_tim13_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM13EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM13EN;
	}
}

void hal_rcc_tim14_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_TIM14EN;
	}
}

void hal_rcc_spi2_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_SPI2EN;
	}
}

void hal_rcc_spi3_enable(_Bool enabled) {
	if (enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;
	} else {
		RCC->APB1ENR &= ~RCC_APB1ENR_SPI3EN;
	}
}
