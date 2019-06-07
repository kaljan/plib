#include "stm32f7xx.h"


#define VECT_TAB_OFFSET  0x00
#define TIMEOUT_MAX	1000000


static int timeout = 0;

#define MCO2_ENABLE 1
/**
 *
 */
static void SetSystemClock216MHz(void) {
	uint32_t PLL_M = 8, PLL_Q = 9, PLL_R = 7, PLL_N = 216, PLL_P = 2;

#if defined HSE_VALUE
	PLL_M = 4;
	RCC->CR |=
		RCC_CR_CSSON |
		RCC_CR_HSEON;

	timeout = TIMEOUT_MAX;

	do {
		timeout--;
		if (timeout < 0) {
			CatchClockFailed();
		}
	} while(!(RCC->CR & RCC_CR_HSERDY));

	if (!(RCC->CR & RCC_CR_CSSON)) {
		CatchClockFailed();
	}
#endif

	/* Select regulator voltage output Scale 1 mode */
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR1 |= PWR_CR1_VOS;

	 /* Enable Over Drive to reach the 216MHz frequency */
	PWR->CR1 |= PWR_CR1_ODEN;

	timeout = TIMEOUT_MAX;

	do {
		timeout--;
		if (timeout < 0) {
			while (1);
		}
	} while(!(PWR->CSR1 & PWR_CSR1_ODRDY));

	PWR->CR1 |= PWR_CR1_ODSWEN;

	timeout = TIMEOUT_MAX;

	do {
		timeout--;
		if (timeout < 0) {
			while (1);
		}
	} while(!(PWR->CSR1 & PWR_CSR1_ODSWRDY));

    /* HCLK = SYSCLK / 1*/
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	/* PCLK2 = HCLK / 2*/
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV2;

	/* PCLK1 = HCLK / 4*/
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV4;

	RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) - 1) << 16) |
    	/*(RCC_PLLCFGR_PLLSRC_HSI) | */(PLL_Q << 24) | (PLL_R << 28);

	/* Enable the main PLL */
	RCC->CR |= RCC_CR_PLLON;

	timeout = TIMEOUT_MAX;

	do {
		timeout--;
		if (timeout < 0) {
			while (1);
		}
	} while(!(RCC->CR & RCC_CR_PLLRDY));

	/* Configure Flash prefetch, Instruction cache, Data cache and wait state */
	FLASH->ACR = FLASH_ACR_LATENCY_7WS;

	/* Select the main PLL as system clock source */
	RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
	RCC->CFGR |= RCC_CFGR_SW_PLL;

	timeout = TIMEOUT_MAX;

	do {
		timeout--;
		if (timeout < 0) {
			while (1);
		}
	} while(!(RCC->CFGR & RCC_CFGR_SWS_PLL));
}

/**
 *
 */
void SystemInit(void) {
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
	SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
#endif
	int timeout;

    /* Reset the RCC clock configuration to the default reset state ------------*/
    /* Set HSION bit */
	RCC->CR |= (uint32_t)0x00000001;
	RCC->CR |=
		RCC_CR_CSSON/* |
		RCC_CR_HSEON*/;
	timeout = TIMEOUT_MAX;

	do {
		timeout--;
		if (timeout < 0) {
			while (1);
		}
	} while(!(RCC->CR & RCC_CR_HSIRDY));


	if (!(RCC->CR & RCC_CR_CSSON)) {
		while(1);
	}

	/* Reset CFGR register */
	RCC->CFGR = 0x00000000;

	/* Reset HSEON, CSSON and PLLON bits */
	RCC->CR &= (uint32_t)0xFEF6FFFF;

	/* Reset PLLCFGR register */
	RCC->PLLCFGR = 0x24003010;

	/* Reset HSEBYP bit */
	RCC->CR &= (uint32_t)0xFFFBFFFF;

	/* Disable all interrupts */
	RCC->CIR = 0x00000000;

#if MCO1_ENABLE == 1
	RCC->CFGR |=
		RCC_CFGR_MCO1PRE_2 |
		RCC_CFGR_MCO1PRE_1;
#endif

#if MCO2_ENABLE == 1
	RCC->CFGR |=
		RCC_CFGR_MCO2PRE_2 |
		RCC_CFGR_MCO2PRE_1;
#endif

	SetSystemClock216MHz();

#if MCO1_ENABLE == 1
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER8_1;
	GPIOA->OSPEEDR |=
		GPIO_OSPEEDER_OSPEEDR8_0 |
		GPIO_OSPEEDER_OSPEEDR8_1;
#endif

#if MCO2_ENABLE == 1
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER9_1;
	GPIOC->OSPEEDR |=
		GPIO_OSPEEDER_OSPEEDR9_0 |
		GPIO_OSPEEDER_OSPEEDR9_1;
#endif

	/* Configure the Vector Table location add offset address ------------------*/
#ifdef VECT_TAB_SRAM
	SCB->VTOR = RAMDTCM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
	SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif
}
