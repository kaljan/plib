/**
 * @file 	graph_cfg.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "graph.h"

extern void graph_callback(volatile void * arg);

graph_t graph_context;
s_node_t fb1_node;
s_node_t fb2_node;

uint8_t fb1[GLCD_BUFFER_SIZE];
uint8_t fb2[GLCD_BUFFER_SIZE];

buffer_t frame_buffer1 = {
	.data = fb1,
	.curr = NULL,
	.size = GLCD_BUFFER_SIZE,
	.bytes = 0
};

buffer_t frame_buffer2 = {
	.data = fb2,
	.curr = NULL,
	.size = GLCD_BUFFER_SIZE,
	.bytes = 0
};

s_node_t fb1_node = {
	.object = &frame_buffer1,
	.next = &fb2_node,
};

s_node_t fb2_node = {
	.object = &frame_buffer2,
	.next = &fb1_node,
};

hal_callback_t graph_handler = {
	.callback = graph_callback,
	.on_failed = NULL,
	.object = &graph_context,
};

graph_t graph_context = {
	.id = 0,
	.initialized = false,
	.busy = false,
	.glcd = NULL,
	.curr_frame = &frame_buffer1,
	.frame_buffer = &fb1_node,
	.handler = &graph_handler,
};

