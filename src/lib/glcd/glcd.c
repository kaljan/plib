/**
 * @file 	glcd.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "glcd.h"

_Bool glcd_get_busy_status(glcd_t * context) {
	if (context && context->is_busy) {
		return context->is_busy(context->driver);
	}
	return false;
}

int glcd_init(glcd_t * context, hal_callback_t * callback) {
	int ret = -1;
	if (context && context->init &&
		((ret = context->init((void *)context->driver, callback)) == 0)) {
	}
	return ret;
}

void glcd_deinit(glcd_t ** context) {
	if (context && *context &&
		(*context)->deinit) {
		(*context)->deinit((*context)->driver);
		context = NULL;
	}
}

int glcd_write_data(glcd_t * context,
	hal_callback_t * callback, buffer_t * buffer) {
	int ret = -1;
	if (context && context->write_buffer) {
		return context->write_buffer(context->driver, callback, buffer);
	}
	return ret;
}


//_Bool glcd_swap_buffer

//extern s_node_t glcd_db_node_1;
//extern s_node_t glcd_db_node_2;
//
//#define GLCD_BUFFER_SIZE 1024
//
//uint8_t glcd_data_buffer_1[GLCD_BUFFER_SIZE];
//
//typedef struct _glcd_buffer_t {
//	uint8_t * data;
//	uint8_t * curr;
//	size_t size;
//} glcd_buffer_t;
//
//glcd_buffer_t glcd_buffer_1 = {
//	.data = (void *)glcd_data_buffer_1,
//	.curr = NULL,
//	.size = GLCD_BUFFER_SIZE,
//};
//
//s_node_t glcd_db_node_1 = {
//	.object = (void *)&glcd_buffer_1,
//	.next = (void *)&glcd_db_node_2,
//};
//
//uint8_t glcd_data_buffer_2[GLCD_BUFFER_SIZE];
//
//glcd_buffer_t glcd_buffer_2 = {
//	.data = (void *)glcd_data_buffer_1,
//	.curr = NULL,
//	.size = GLCD_BUFFER_SIZE,
//};
//
//s_node_t glcd_db_node_2 = {
//	.object = (void *)&glcd_buffer_2,
//	.next = (void *)&glcd_db_node_1,
//};
