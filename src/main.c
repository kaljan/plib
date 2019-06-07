/*
 * RCC
 * GPIO
 * TIM
 * EXTI
 * DMA
 * ADC
 * DAC
 * RTC
 * CAN
 * SPI
 * UART
 * I2C
 * I2S
 * SDIO
 */
//extern void hal_gpio_test(void);
//extern void sw_timer_test(void);
//extern void gcdi_port_test(void);
//extern void sw_timer_test(void);
extern void gcdi_port_test(void);
int main(void) {
//	sw_timer_test();
	gcdi_port_test();
	return 0;
}
