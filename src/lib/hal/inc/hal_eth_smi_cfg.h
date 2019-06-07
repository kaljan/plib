#ifndef HAL_ETH_SMI_CFG_H
#define HAL_ETH_SMI_CFG_H

#include "hal.h"
#include "hal_gpio.h"

typedef enum {
	AHB_CK_DIV_42 = 0,	// 60-100 MHz
	AHB_CK_DIV_62 = 1,	// 100-150 MHz
	AHB_CK_DIV_16 = 2,	// 20-35 MHz
	AHB_CK_DIV_26 = 3,	// 35-60 MHz
	AHB_CK_DIV_102 = 4,	// 150-216 MHz
} hal_eth_smi_mdc_t;

typedef struct _hal_eth_smi_t {
	uint8_t p_addr;
	uint8_t m_addr;
	hal_eth_smi_mdc_t clock_range;
	_Bool write;
	void * phy;
	hal_gpio_t * mdc_gpio;
	hal_gpio_t * mdio_gpio;
} hal_eth_smi_t;

#endif // HAL_ETH_SMI_CFG_H
