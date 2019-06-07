#include "buffer.h"
#include <string.h>

/**
 *
 * @param size
 * @return
 */
buffer_t * create_buffer(size_t size) {
	buffer_t * buf = malloc(sizeof(buffer_t));
	if (buf) {
		if (!(buf->data = malloc(size))) {
			free(buf);
			return NULL;
		}
		memset(buf->data, 0, size);
		buf->size = size;
		buf->bytes = 0;
	}
	return buf;
}

/**
 *
 * @param buf
 */
void destroy_buffer(void ** object) {
	if (object && *object) {
		if (((buffer_t *)(*object))->data) {
			free(((buffer_t *)(*object))->data);
		}
		free(*object);
		*object = NULL;
	}
}

void flush_buffer(buffer_t * buffer) {
	if (buffer && buffer->data) {
		memset(buffer->data, 0, buffer->size);
	}
}

/**
 *
 * @param buf
 * @param data
 * @param size
 */
ssize_t write_buffer(buffer_t * buf, uint8_t * data, size_t size) {
	if (buf && data) {
		if  (buf->bytes < buf->size) {
			if (buf->bytes + size >= buf->size) {
				size = buf->size - buf->bytes;
			}
			memmove((void *)(buf->data + buf->bytes), (void *)data, size);
			buf->bytes += size;
			return size;
		}
		return 0;
	}
	return -1;
}

/**
 *
 * @param buf
 * @param data
 * @param size
 * @return
 */
ssize_t read_buffer(buffer_t * buf, uint8_t * data, size_t size) {
	if (buf && data) {
		if (size < buf->bytes) {
			memmove(data, buf->data, size);
			buf->bytes -= size;
			memmove(buf->data, (buf->data + size), buf->bytes);
			return (ssize_t)size;
		}
		size = buf->bytes;
		memmove(data, buf->data, size);
		buf->bytes = 0;
		return (ssize_t)size;
	}
	return -1;
}

buffer_t * swap_buffer(s_node_t ** item) {
	if (item && *item) {
		*item = (s_node_t *)((*item)->next);
		return (buffer_t *)(*item)->object;
	}
	return NULL;
}

