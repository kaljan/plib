/**
 * @file 	glcd_io.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include <glcd_io.h>

int glcd_io_connect(glcd_io_t * context) {
	if (context && context->connect) {
		return context->connect(context->port);
	}
	return -1;
}

void glcd_io_disconnect(glcd_io_t * context) {
	if (context && context->disconnect) {
		context->disconnect(context->port);
	}
}

int glcd_io_write_data(glcd_io_t * context, hal_callback_t * handler, void * data, size_t size) {
	if (context && context->write_data) {
		return context->write_data(context->port, handler, data, size);
	}
	return -1;
}

int glcd_io_write_command(glcd_io_t * context, hal_callback_t * handler, void * data, size_t size) {
	if (context && context->write_data) {
		return context->write_command(context->port, handler, data, size);
	}
	return -1;
}
