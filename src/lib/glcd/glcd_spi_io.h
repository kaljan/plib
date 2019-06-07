/**
 * @file 	glcd_spi_io.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef GLCD_SPI_IO_H
#define GLCD_SPI_IO_H

#include "glcd_io.h"
#include "hal_spi.h"
#include "hal_gpio.h"
#include "hwprof.h"

typedef struct _gcdi_spi_io_t {
	int id;
	hal_spi_dsc_t * spi_dsc;
	hal_gpio_t * gcdi_dc;
	hal_gpio_t * gcdi_cs;
	void (*on_failed)(volatile void *, hal_error_t);
	void (*callback)(volatile void *);
	volatile void * context;
} gcdi_spi_io_t;

extern gcdi_spi_io_t sh1106_glcd_spi_io;
extern glcd_io_t sh1106_glcd_io;
extern hal_interface_t glcd_spi6_handler;

int glcd_spi_io_connect(void * context);
void glcd_spi_io_disconnect(void *);
int glcd_spi_io_write_data(void *, hal_callback_t * handler, void *, size_t);
int glcd_spi_io_write_command(void *, hal_callback_t * handler, void *, size_t);
void glcd_spi_io_transfer_complete(volatile void * arg);
void glcd_spi_io_err_handler(volatile void *arg, hal_error_t error);

#endif // GLCD_SPI_IO_H
