/**
 * @file 	glcd_sh1106.h
 * @author	kaljan
 * @version	0.0.0
 * @date	May 10, 2019
 *
 * @brief
 */

#ifndef GLCD_SH1106_H
#define GLCD_SH1106_H

#include "glcd_io.h"
#include "glcd.h"
#include "hal_gpio.h"
#include "hal_spi.h"
#include "hal_tim.h"
#include "buffer.h"

#define PUMP_VOLTAGE_6_4	0x30
#define PUMP_VOLTAGE_7_4	0x31
#define PUMP_VOLTAGE_8_0	0x32
#define PUMP_VOLTAGE_9_0	0x33
#define SET_CONTRAST		0x81
#define SEGMENT_REMAP_LEFT	0xA0
#define SEGMENT_REMAP_RIGHT	0xA1
#define ENTRIE_DISPLAY_OFF	0xA4
#define ENTRIE_DISPLAY_ON	0xA5
#define REVERSE_ON			0xA7
#define REVERSE_OFF			0xA6
#define SET_MULT_RATION 	0xA8
#define SET_DC_DC_CONTROL	0xAD
#define DC_DC_EXT			0x8A
#define DC_DC_INT			0x8B
#define DISPLAY_ON			0xAF
#define DISPLAY_OFF			0xAE
#define SCAN_COM_0_N		0xC0
#define SCAN_COM_N_0		0xC8
#define SET_DISP_OFFSET		0xD3
#define SET_CLOCK_CONFIG	0xD5
#define SET_CHARGE_PERIOD	0xD9
#define SET_COMM_CONFIG		0xDA
#define SEQUENTIAL_MODE		0x02
#define ALTERNATIVE_MODE	0x12
#define SET_VCOM_CONFIG		0xDB
#define SH1106_NOP			0xE3

#define SH1106_CFG_SIZE		16
#define SH1106_OFFSET		2

typedef enum {
	SH1106_IDLE,
	SH1106_RESET,
	SH1106_CFGR,
	SH1106_PCFGR,
	SH1106_PWROFF,
	SH1106_PWRON,
	SH1106_ADDR,
	SH1106_DATA,
	SH1106_FAILED,
} sh1106_state;

typedef struct _sh1106_driver_t {
	char * name;
	volatile _Bool initialized;
	volatile _Bool busy;
	volatile sh1106_state state;
	int height;
	int width;
	uint8_t page;
	uint8_t offset;
	uint8_t * cfg;
	uint8_t * cmd;
	int cmd_size;
	uint8_t * curr;
	int data_size;
	hal_tim_t * timer;
	hal_gpio_t * reset_pin;
	void * spi_cfg;
	glcd_io_t * glcd_io;
	hal_callback_t * init_handler;
	hal_callback_t * data_handler;
	void (*callback)(volatile void *);
	void (*on_failed)(volatile void *, hal_error_t);
	volatile void * arg;
} sh1106_driver_t;

extern sh1106_driver_t sh1106_driver;
extern glcd_t sh1106_glcd_interface;

_Bool sh1106_busy(volatile void * context);
_Bool sh1106_tim_callback(volatile void * arg);
void sh1106_spi_callback(volatile void * arg);
int sh1106_init(void * context, hal_callback_t * handler);
void sh1106_write_callback(volatile void * context);
int sh1106_write_buffer(void * context,
	hal_callback_t * handler, buffer_t * buffer);
void sh1106_on_failed(volatile void *arg, hal_error_t error);
#endif // GLCD_SH1106_H
