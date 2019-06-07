#ifndef BUF_H
#define BUF_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include "node.h"

typedef struct _buffer_t {
	void * data;
	void * curr;
	size_t size;
	size_t bytes;
} buffer_t;

buffer_t * create_buffer(size_t size);
void destroy_buffer(void ** object);
void flush_buffer(buffer_t * buffer);
ssize_t write_buffer(buffer_t * buf, uint8_t * data, size_t size);
ssize_t read_buffer(buffer_t * buf, uint8_t * data, size_t size);

buffer_t * swap_buffer(s_node_t ** item);

#endif // BUF_H
