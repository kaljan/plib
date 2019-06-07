/**
 * @file 	graph.c
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#include "graph.h"
#include <math.h>

extern graph_t graph_context;
extern const uint8_t pixfont5x8[128][5];
extern const uint16_t pixfont8x16[256][8];

/**
 *
 * @return
 */
graph_t *graph_get_context(void) {
	if (!graph_context.initialized) {
		return &graph_context;
	}
	return NULL;
}

/**
 *
 * @param context
 * @return
 */
_Bool graph_busy(graph_t * context) {
	if (context) {
		return context->busy;
	}
	return false;
}

/**
 *
 * @param arg
 */
void graph_callback(volatile void * arg) {
	if (arg) {
		graph_t * context = (graph_t *)arg;
		context->busy = false;
		if (!context->initialized) {
			context->initialized = true;
			return;
		}
	}
}

/**
 *
 * @param context
 */
void graph_swap_buffer(graph_t * context) {
	if (context && context->initialized && !context->busy) {
		context->busy = true;
		glcd_write_data(context->glcd, context->handler, context->curr_frame);
		context->curr_frame = swap_buffer(&context->frame_buffer);
	}
}

/**
 *
 * @param context
 */
void graph_flush(graph_t * context) {
	if (context) {
		flush_buffer(context->curr_frame);
	}
}

/**
 *
 * @param context
 * @return
 */
int graph_init(graph_t * context) {
	int ret = -1;
	if (context && !context->initialized) {
		ret = 1;
		if (!context->busy) {
			context->busy = true;
			ret = -1;
			if ((context->glcd = glcd_get_context())) {
				ret = glcd_init(context->glcd, context->handler);
			}
		}
	}
	return ret;
}

/**
 *
 * @param context
 * @param c
 * @param line
 * @param offset
 * @param color
 */
void graph_draw_char_5x8(graph_t * context, char c, int line, int offset, graph_color_t color) {
	if (context && context->curr_frame && context->curr_frame->data) {
		if (line > 7 && line < 0) {
			line = 0;
		}

		if (offset > 127 && offset < 0) {
			offset = 0;
		}

		int addr = offset + (line * 128);
		context->curr_frame->curr = context->curr_frame->data + (offset + (line * 128));
		for (int i = 0; i < 5; i++) {
			*((uint8_t *)context->curr_frame->curr) =
				((color) ? pixfont5x8[c][i] : ~pixfont5x8[c][i]);
			context->curr_frame->curr++;
			if (context->curr_frame->curr >
				(context->curr_frame->data + context->curr_frame->size)) {
				context->curr_frame->curr = context->curr_frame->data;
			}
		}
	}
}

/**
 *
 * @param context
 * @param c
 * @param line
 * @param offset
 * @param color
 */
void graph_draw_char_8x16(graph_t * context, char c, int line, int offset, graph_color_t color) {
	if (context && context->curr_frame && context->curr_frame->data) {
		if (line > 7 && line < 0) {
			line = 0;
		}

		if (offset > 127 && offset < 0) {
			offset = 0;
		}

		context->curr_frame->curr = context->curr_frame->data + (offset + (line * 128));
		for (int i = 0; i < 8; i++) {
			*((uint8_t *)context->curr_frame->curr) =
				((color) ? ((uint8_t)((pixfont8x16[c][i] & 0x00FF))) :
					~((uint8_t)((pixfont8x16[c][i] & 0x00FF))));
			context->curr_frame->curr++;
			if (context->curr_frame->curr >
				(context->curr_frame->data + context->curr_frame->size)) {
				context->curr_frame->curr = context->curr_frame->data;
			}
		}

		context->curr_frame->curr += 120;

		for (int i = 0; i < 8; i++) {

			*((uint8_t *)context->curr_frame->curr) = ((color) ?
				(uint8_t)((pixfont8x16[c][i] & 0xFF00) >> 8) :
				~((uint8_t)((pixfont8x16[c][i] & 0xFF00) >> 8)));
			context->curr_frame->curr++;
		}
		if (context->curr_frame->curr >
			(context->curr_frame->data + context->curr_frame->size)) {
			context->curr_frame->curr = context->curr_frame->data;
		}
	}
}

/**
 *
 * @param context
 * @param str
 * @param line
 * @param offset
 * @param color
 */
void graph_draw_string_5x8(graph_t * context, const char * str,
	int line, int offset, graph_color_t color) {
	if (str) {
		while (*str) {
			graph_draw_char_5x8(context, *str, line, offset, color);
			offset += 6;
			if (offset > 127) {
				offset = 0;
				line++;
				if (line > 7) {
					line = 0;
				}
			}
			str++;
		}
	}
}

/**
 *
 * @param context
 * @param str
 * @param line
 * @param offset
 * @param color
 */
void graph_draw_string_8x16(graph_t * context, const char * str,
	int line, int offset, graph_color_t color) {
	if (str) {
		while (*str) {
			graph_draw_char_8x16(context, *str, line, offset, color);
			offset += 8;
			if (offset > 127) {
				offset = 0;
				line += 2;
				if (line > 7) {
					line = 0;
				}
			}
			str++;
		}
	}
}

/**
 *
 * @param context
 * @param x
 * @param y
 * @param color
 */
void graph_draw_pixel(graph_t * context, int x, int y, graph_color_t color) {
	if (context && context->curr_frame && context->curr_frame->data) {
		if (color) {
			*((uint8_t *)(context->curr_frame->data + x + (128 * ((y & 0x0038) >> 3)))) |=
				(((uint8_t)1) << (y & 0x07));
			return;
		}
		*((uint8_t *)(context->curr_frame->data + x + (128 * ((y & 0x0038) >> 3)))) &=
			~(((uint8_t)1) << (y & 0x07));
	}
}

/**
 *
 * @param context
 * @param start_x
 * @param start_y
 * @param end_x
 * @param end_y
 * @param color
 */
void graph_draw_line(graph_t * context, int start_x, int start_y,
	int end_x, int end_y, graph_color_t color) {
	int dx = fabs(end_x - start_x);
	int dy = fabs(end_y - start_y);
	int sx = (start_x < end_x) ? 1 : -1;
	int sy = (start_y < end_y) ? 1 : -1;
	int error = dx - dy;
	int error2;

	for(;;) {
		graph_draw_pixel(context, start_x, start_y, color);
		if (start_x == end_x && start_y == end_y) break;

		error2 = error * 2;

		if (error2 > -dy) error -= dy, start_x += sx;
		if (error2 < dx) error += dx, start_y += sy;
	}
}

/**
 *
 * @param context
 * @param xc
 * @param yc
 * @param rx
 * @param ry
 * @param color
 */
void graph_draw_ellipse(graph_t * context, int xc, int yc, int rx, int ry, graph_color_t color)
{
	int x = 0, y = ry, p = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4);

	while ((2 * x * ry * ry) < (2 * y * rx * rx)) {
		graph_draw_pixel(context, xc + x, yc - y , color);
		graph_draw_pixel(context, xc - x, yc + y , color);
		graph_draw_pixel(context, xc + x, yc + y , color);
		graph_draw_pixel(context, xc - x, yc - y , color);

		if (p<0) {
			x = x + 1;
			p = p + (2 * ry * ry * x) + (ry * ry);
		} else {
			x = x + 1;
			y = y - 1;
			p = p + (2 * ry * ry * x + ry * ry) - (2 * rx * rx * y);
		}
	}

	p = ((float)x + 0.5) * ((float)x + 0.5) * ry * ry +
		(y - 1) * (y - 1) * rx * rx - rx * rx * ry * ry;

	while (y >= 0) {
		graph_draw_pixel(context, xc + x, yc - y, color);
		graph_draw_pixel(context, xc - x, yc + y, color);
		graph_draw_pixel(context, xc + x, yc + y, color);
		graph_draw_pixel(context, xc - x, yc - y, color);

		if (p > 0) {
			y = y - 1;
			p = p - (2 * rx * rx * y) + (rx * rx);

		} else {
			y = y - 1;
			x = x + 1;
			p = p + (2 * ry * ry * x) - (2 * rx * rx * y) - (rx * rx);
		}
	}
}

/**
 *
 * @param context
 * @param x
 * @param y
 * @param w
 * @param h
 * @param color
 */
void graph_draw_rect(graph_t * context, int x, int y, int w, int h, uint16_t color) {
	graph_draw_line(context, x, y, x, y + h, color);
	graph_draw_line(context, x, y, x + w, y, color);
	graph_draw_line(context, x, y + h, x + w, y + h, color);
	graph_draw_line(context, x + w, y, x + w, y + h, color);
}

/**
 *
 * @param context
 * @param x
 * @param y
 * @param w
 * @param h
 * @param color
 */
void graph_fill_rect(graph_t * context, int x, int y, int w, int h, uint16_t color) {
	for (int i = 0; i < h; i++) {
		graph_draw_line(context, x, y + i, x + w, y + i, color);
	}
}
