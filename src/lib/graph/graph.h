/**
 * @file 	graph.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "glcd.h"

#define GLCD_BUFFER_SIZE	1024

typedef uint8_t graph_color_t;

typedef struct _graph_t {
	int id;
	volatile _Bool initialized;
	volatile _Bool busy;
	glcd_t * glcd;
	buffer_t * curr_frame;
	s_node_t * frame_buffer;
	hal_callback_t * handler;
} graph_t;

graph_t *graph_get_context(void);
_Bool graph_busy(graph_t *context);
void graph_swap_buffer(graph_t * context);
void graph_flush(graph_t * context);
int graph_init(graph_t *context);

void graph_draw_char_5x8(graph_t * context, char c, int line, int offset, graph_color_t color);
void graph_draw_char_8x16(graph_t * context, char c, int line, int offset, graph_color_t color);
void graph_draw_string_5x8(graph_t * context, const char * str, int line, int offset, graph_color_t color);
void graph_draw_string_8x16(graph_t * context, const char * str, int line, int offset, graph_color_t color);

void graph_draw_pixel(graph_t * context, int x, int y, graph_color_t color);
void graph_draw_line(graph_t * context, int x1, int y1, int x2, int y2, graph_color_t color);
void graph_draw_ellipse(graph_t * context, int xc, int yc, int rx, int ry, graph_color_t color);
void graph_draw_rect(graph_t * context, int x, int y, int w, int h, uint16_t color);
void graph_fill_rect(graph_t * context, int x, int y, int w, int h, uint16_t color);

#endif // GRAPH_H
