/**
 * @file 	glcd_spi_io_cfg.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "glcd_spi_io.h"

gcdi_spi_io_t sh1106_glcd_spi_io = {
	.spi_dsc = NULL,
	.gcdi_cs = &sh1106_cs,
	.gcdi_dc = &sh1106_dc,
	.callback = NULL,
	.context = NULL,
};

glcd_io_t sh1106_glcd_io = {
	.port = &sh1106_glcd_spi_io,
	.connect = glcd_spi_io_connect,
	.disconnect = glcd_spi_io_disconnect,
	.write_data = glcd_spi_io_write_data,
	.write_command = glcd_spi_io_write_command,
};

hal_interface_t glcd_spi6_handler = {
	.context = &sh1106_glcd_spi_io,
	.transfer_complete = glcd_spi_io_transfer_complete,
	.on_received = NULL,
	.on_failed = glcd_spi_io_err_handler,
};
