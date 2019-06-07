/**
 * @file 	glcd_io.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef GCDI_IO_H
#define GCDI_IO_H

#include "hal.h"

typedef struct _glcd_io_t {
	void * port;
	int (*connect)(void *);
	void (*disconnect)(void *);
	int (*write_data)(void *, hal_callback_t *, void *, size_t);
	int (*write_command)(void *, hal_callback_t *, void *, size_t);
} glcd_io_t;

glcd_io_t * glcd_get_interface(void * config);
int glcd_io_connect(glcd_io_t * context);
void glcd_io_disconnect(glcd_io_t * context);
int glcd_io_write_data(glcd_io_t * context,
	hal_callback_t * handler, void * data, size_t size);
int glcd_io_write_command(glcd_io_t * context,
	hal_callback_t * handler, void * data, size_t size);

#endif // GCDI_IO_H
