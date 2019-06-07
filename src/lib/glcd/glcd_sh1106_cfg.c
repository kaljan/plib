/**
 * @file 	glcd_sh1106_cfg.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "glcd_sh1106.h"
#include "hwprof.h"

hal_spi_cfg_t sh1106_spi_cfg = {
	.master = true,
	.cpha = true,
	.cpol = true,
	.lsb_first = false,
	.datasize = DS_8_BITS,
	.baudrate = BR_FPCLR_32,
	.soft_slave_mgmt = true,
	.internal_slave_select = true,
	.rx_enabled = false,
	.tx_enabled = true,
};

hal_callback_t sh1106_init_handler = {
	.callback = sh1106_spi_callback,
	.on_failed = sh1106_on_failed,
	.object = &sh1106_driver,
};

hal_callback_t sh1106_data_handler = {
	.callback = sh1106_write_callback,
	.on_failed = sh1106_on_failed,
	.object = &sh1106_driver,
};

uint8_t sh1106_cfg[SH1106_CFG_SIZE] = {
	SEGMENT_REMAP_LEFT,
	SET_COMM_CONFIG,
	ALTERNATIVE_MODE,
	SCAN_COM_0_N,
	SET_MULT_RATION,
	0x3F,
	SET_CLOCK_CONFIG,
	0x80,
	SET_VCOM_CONFIG,
	0x60,
	SET_CONTRAST,
	180,
	PUMP_VOLTAGE_9_0,
	SET_DC_DC_CONTROL,
	DC_DC_INT,
	DISPLAY_ON
};

uint8_t hs1106_command_data[4];

sh1106_driver_t sh1106_driver = {
	.name = "sh1106",
	.initialized = false,
	.height = 64,
	.width = 128,
	.busy = false,
	.state = SH1106_IDLE,
	.page = 0,
	.offset = 2,
	.cfg = sh1106_cfg,
	.cmd = hs1106_command_data,
	.cmd_size = 3,
	.timer = &tim7_delay,
	.reset_pin = &sh1106_reset,
	.spi_cfg = &sh1106_spi_cfg,
	.glcd_io = NULL,
	.init_handler = &sh1106_init_handler,
	.data_handler = &sh1106_data_handler,
	.callback = NULL,
	.on_failed = NULL,
	.arg = NULL,
};

glcd_t sh1106_glcd_interface = {
	.driver = &sh1106_driver,
	.is_busy = sh1106_busy,
	.init = sh1106_init,
	.deinit = NULL, // TODO implement deinit
	.write_buffer = sh1106_write_buffer,
};
