#include "hal_rcc.h"

void hal_rcc_gpioa_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOAEN;
	}
}

void hal_rcc_gpiob_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOBEN;
	}
}

void hal_rcc_gpioc_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOCEN;
	}
}

void hal_rcc_gpiod_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIODEN;
	}
}

void hal_rcc_gpioe_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOEEN;
	}
}

void hal_rcc_gpiof_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOFEN;
	}
}

void hal_rcc_gpiog_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOGEN;
	}
}

void hal_rcc_gpioh_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_GPIOHEN;
	}
}

void hal_rcc_dma1_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA1EN;
	}
}

void hal_rcc_dma2_enable(_Bool enabled) {
	if (enabled) {
		RCC->AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	} else {
		RCC->AHB1ENR &= ~RCC_AHB1ENR_DMA2EN;
	}
}
