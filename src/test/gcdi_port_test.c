#include <di.h>
#include "graph.h"
#include <stdio.h>
#include "hwprof.h"


volatile int encoder_value = 0;
volatile int slider_value = 0;
void qencoder_handler(volatile void * arg, int value) {

	encoder_value += value;
	if (encoder_value > 56) {
		encoder_value = 56;
	}
	if (encoder_value < 0) {
		encoder_value = 0;
	}
}

void gcdi_port_test(void) {
	int ret, index = 0;
	char str[256];

	hal_rcc_gpioa_enable(true);
	hal_rcc_gpiob_enable(true);
	hal_rcc_gpioc_enable(true);
	hal_rcc_gpiod_enable(true);
	hal_rcc_gpioe_enable(true);
	hal_rcc_gpiof_enable(true);
	hal_qenc_init(&qencoder, qencoder_handler, NULL);

	graph_t * g_context = graph_get_context();
	if ((ret = graph_init(g_context)) == 0) {
		while (1) {
			if (!g_context->busy) {

				graph_flush(g_context);
				graph_draw_string_8x16(g_context, "HELLO WORLD\0", 1, 0, 1);
				graph_draw_string_8x16(g_context, "HELLO WORLD\0", 3, 0, 0);

				graph_draw_rect(g_context, 100, 2, 12, 59, 1);
				graph_fill_rect(g_context, 102, 60-encoder_value, 8, encoder_value, 1);
				sprintf(str, "enc: %5d", encoder_value);
				graph_draw_string_5x8(g_context, str, 5, 0, 1);
				sprintf(str, "enc: %5d", encoder_value);
				graph_draw_string_5x8(g_context, str, 6, 0, 0);

				graph_swap_buffer(g_context);
			}
		}
	}

	while(1);
}
