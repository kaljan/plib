#ifndef HAL_TYPES_H
#define HAL_TYPES_H

#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "buffer.h"

typedef enum _status_t {
	H_IDLE = 2,
	H_BUSY = 1,
	H_READY = 0,
	H_FAILED = -1
} hal_status_t;

typedef enum _event_t {
	RISING,
	FALLING,
	BOTH
} hal_event_t;

typedef enum _direction_t {
	OUTPUT,
	INPUT
} direction_t;

typedef enum {
	HAL_OK = 0,
	HAL_ERR_SPI_MODF = 1,
	HAL_ERR_SPI_OVR = 2,
	HAL_ERR_SPI_FRE = 3,
	HAL_ERR_SPI_UDR = 4,
	HAL_ERR_SPI_CRCERR = 5,
	HAL_ERR_DMA_TE = 6,
	HAL_ERR_DMA_DME = 7,
} hal_error_t;

typedef struct _hal_callback_t {
	void (*callback)(volatile void *);
	void (*on_failed)(volatile void *, hal_error_t);
	volatile void * object;
} hal_callback_t;

typedef struct _hal_interface_t {
	volatile void * context;
	void (*transfer_complete)(volatile void *);
	void (*on_received)(volatile void *, buffer_t *);
	void (*on_failed)(volatile void *, hal_error_t);
} hal_interface_t;

typedef struct _hal_slot_t {
	hal_callback_t * on_success;
	hal_callback_t * on_failed;
} hal_slot_t;

typedef void (*event_callback_t)(hal_event_t event);
typedef void (*callback_t)(void);

/**
 * Базовый интерфейс периферии.
 */

#endif // HAL_TYPES_H
