#include "dip.h"
#include "graph.h"
#include <stdio.h>

void gcdi_port_test(void) {
	int ret, index = 0;
	char str[256];

	hal_rcc_gpioa_enable(true);
	hal_rcc_gpiob_enable(true);
	hal_rcc_gpioc_enable(true);
	hal_rcc_gpiod_enable(true);
	hal_rcc_gpiof_enable(true);

	graph_t * g_context = graph_get_context();
	if ((ret = graph_init(g_context)) == 0) {
		while (1) {
			if (!g_context->busy) {
//				graph_draw_string_5x8(g_context, "Good morning, \0", 0, 0, 1);
//				graph_draw_string_5x8(g_context, "Rej\0", 1, 84, 1);
//				graph_draw_string_8x16(g_context, ";)\0", 3, 61, 1);
				graph_draw_string_8x16(g_context, "HELLO WORLD\0", 1, 0, 1);
				graph_draw_string_8x16(g_context, "HELLO WORLD\0", 3, 0, 0);
				graph_draw_line(g_context, 5, 5, 32, 50, 1);
				graph_draw_line(g_context, 5, 5, 120, 57, 1);
				graph_fill_rect(g_context, 42, 17, 20, 30, 1);
				graph_draw_ellipse(g_context, 52, 32, 10, 15, 0);
				graph_draw_ellipse(g_context, 64, 32, 44, 24, 1);
//				graph_draw_rect(g_context, 100, 12, 12, 15, 1);
				graph_draw_rect(g_context, 100, 2, 12, 30, 1);
				graph_fill_rect(g_context, 102, 14, 8, 17, 1);
//				sprintf(str, "index: %d", index++);
//				graph_draw_string(g_context, str, 1, 0, 1);
				graph_swap_buffer(g_context);
			}
		}
	}

	while(1);
}

//volatile int i = 0;
//volatile _Bool gcdi_run;
//volatile _Bool finished = false;
//
//#define GCDI_TEST_DATA_SIZE	32
//
//void * pc13_callback(hal_event_t event, void * context) {
//	if (event == RISING) {
//		uint8_t data[GCDI_TEST_DATA_SIZE];
//
//		switch(i) {
//		case 0:
//			led2_pb7.value = false;
//			led3_pb14.value = false;
//			break;
//		case 1:
//			led2_pb7.value = true;
//			led3_pb14.value = false;
//			break;
//		case 2:
//			led2_pb7.value = true;
//			led3_pb14.value = true;
//			break;
//		case 3:
//			led2_pb7.value = false;
//			led3_pb14.value = true;
//			break;
//		default:
//			break;
//		}
//		hal_gpio_set_value(led2_pb7.gpio, led2_pb7.pin, led2_pb7.value);
//		hal_gpio_set_value(led3_pb14.gpio, led3_pb14.pin, led3_pb14.value);
//		i++;
//		if (i > 3) {
//			i = 0;
//		}
//
//		for (int index = 0; index < GCDI_TEST_DATA_SIZE; index++) {
//			data[index] = (uint8_t)index;
//		}
//
//		//		if (glcd_io_write_data((glcd_io_t *)context,
//		//			(void *)data, GCDI_TEST_DATA_SIZE) == 0) {
//		//			gcdi_run = true;
//		//		}
//	}
//	return context;
//}
//
//void sh1106_gcdi_port_callback(volatile void * context) {
//	if (context) {
//		*(volatile _Bool *)(context) = true;
//	}
//}
//
//hal_callback_t glcd_test_handler = {
//	.callback = sh1106_gcdi_port_callback,
//	.object = (void *)&finished,
//};
//
//#define GLCD_FRAME_BUFFER_SIZE	1024
//
//uint8_t glcd_frame_buffer[GLCD_FRAME_BUFFER_SIZE];
//
//buffer_t glcd_test_buffer = {
//	.data = (void *)glcd_frame_buffer,
//	.curr = NULL,
//	.size = GLCD_FRAME_BUFFER_SIZE,
//	.bytes = 0,
//};

//	glcd_t * glcd_port = glcd_get_context();
//
//	if ((ret = glcd_init(glcd_port, &glcd_test_handler)) == 0) {
//		int i = 0;
//		while (glcd_get_busy_status(glcd_port) == true);
//
//		for (i = 0; i < GLCD_FRAME_BUFFER_SIZE; i++) {
//			*((uint8_t *)(glcd_test_buffer.data + i)) = i & 0x000000FF;
//		}
//
//		glcd_write_data(glcd_port, &glcd_test_handler, &glcd_test_buffer);
//		while (1) {
//
//		}
//
//	}

//		di_poll_add(&user_button_pc13, pc13_callback, (void *)glcd_port);
//		hal_gpio_init(&led2_pb7);
//		hal_gpio_init(&led3_pb14);
//			di_poll_event();

//#include "gcdi_port.h"
//
//		if (gcdi_port_write_data((gcdi_port_t *)context,
//			(void *)data, GCDI_TEST_DATA_SIZE) == 0) {
//			gcdi_run = true;
//		}
//	gcdi_port_t * port = gcdi_port_get_context(0);
//	if (port) {


//	}
//void sh1106_gcdi_port_callback(volatile void * context, buffer_t * fff) {
//	if (context) {
//		*(volatile _Bool *)(context) = true;
//	}
//}

//		if (gcdi_port_open(port, sh1106_gcdi_port_callback,
//			(volatile void *)&finished) == 0) {
//
//			di_poll_add(&user_button_pc13, pc13_callback, (void *)port);
//			hal_gpio_init(&led2_pb7);
//			hal_gpio_init(&led3_pb14);
//
//			while(1) {
//				di_poll_event();
//				if (gcdi_run) {
//					while(!finished);
//					finished = false;
//					gcdi_run = false;
//				}
//			}
//		}

//void hal_gpio_test(void) {
//	hal_rcc_gpiob_enable(true);
//	hal_rcc_gpioc_enable(true);
//
//	dip_add(GPIOC, 13, pc13_callback);
//
//	hal_gpio_init(&led2_pb7);
//	hal_gpio_init(&led3_pb14);
//
//	while(1) {
//		dip_poll();
//	}
//}

//void sh1106_timer_callback(void);
//
//sw_timer_t sh1106_timer = {
//	.time = 0,
//	.reload = 0,
//	.callback = sh1106_timer_callback,
//};
//
//void sh1106_timer_callback(void) {
//
//}


//#include "sw_timer.h"
//#include "hal_gpio.h"
//#include "hal_rcc.h"
//
//int i1 = 0, i2 = 0;
//extern hal_gpio_t led2_pb7;
//extern hal_gpio_t led3_pb14;
//_Bool reset_timers = false;
//sw_timer_t * timer1;
//sw_timer_t * timer2;
//sw_timer_t * timer3;
//
//void timer1_callback(void) {
//	static _Bool state = false;
//	state = (state) ? false : true;
//	hal_gpio_set_value(led2_pb7.gpio, led2_pb7.pin, state);
//	i1++;
//}
//
//void timer2_callback(void) {
//	static _Bool state = false;
//	state = (state) ? false : true;
//	hal_gpio_set_value(led3_pb14.gpio, led3_pb14.pin, state);
//	i2++;
//}
//
//void timer3_callback(void) {
////	timer1 = sw_timer_add(1000, true, timer1_callback);
////	timer2 = sw_timer_add(500, true, timer2_callback);
//}
//
//void sw_timer_test(void) {
//	hal_rcc_gpiob_enable(true);
//	hal_rcc_gpioc_enable(true);
//
//	hal_gpio_init(&led2_pb7);
//	hal_gpio_init(&led3_pb14);
//
//	timer1 = sw_timer_create(1000, true, timer1_callback);
//	if (!sw_timer_run(timer1)) {
//		sw_timer_destroy((void **)&timer1);
//	}
//	timer2 = sw_timer_create(500, true, timer2_callback);
//	if (!sw_timer_run(timer2)) {
//		sw_timer_destroy((void **)&timer2);
//	}
//
//	while (1) {
////		if (i1 > 20) {
////			i1 = 0;
////			sw_timer_abort(timer1);
////			timer2 = sw_timer_add(500, true, timer2_callback);
////		}
////		if (i2 > 20) {
////			i2 = 0;
////			sw_timer_abort(timer2);
////		}
//	}
//}
