/**
 * @file 	glcd.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef GLCD_H
#define GLCD_H

#include "hal.h"
#include "buffer.h"

typedef struct _glcd_t {
	void * driver;
	_Bool (*is_busy)(volatile void *);
	int (*init)(void *, hal_callback_t *);
	void (*deinit)(void *);
	int (*write_buffer)(void *, hal_callback_t *, buffer_t *);
} glcd_t;

glcd_t * glcd_get_context(void);
_Bool glcd_get_busy_status(glcd_t * context);
int glcd_init(glcd_t * context, hal_callback_t * callback);
void glcd_deinit(glcd_t ** context);
int glcd_write_data(glcd_t * context,
	hal_callback_t * callback, buffer_t * buffer);

#endif // GLCD_H

//typedef struct _glcd_config_t {
//	int height;
//	int width;
//	int h_offset;
//	int v_offset;
//	int window_height;
//	int window_width;
//	int brightness;
//	int contrast;
//} glcd_config_t;
