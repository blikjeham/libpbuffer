/*
 * pbuffer.c
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pbuffer.h"

pbuffer *pbuffer_new(void)
{
	pbuffer *newbuffer = malloc(sizeof(ssize_t) + sizeof(char *));
	newbuffer->size = 0;
	newbuffer->data = malloc(0);
	
	return(newbuffer);
}

void pbuffer_set(pbuffer *buffer, char *data)
{
	if (buffer->size < strlen(data)) {
		pbuffer_grow(buffer, strlen(data));
	} else {
		/* If not grown, we need to set the size */
		buffer->size = strlen(data);
	}
	memcpy(buffer->data, data, strlen(data));
}

void pbuffer_add(pbuffer *buffer, char *data)
{
	ssize_t size;
	size = buffer->size;
	if (buffer->size < buffer->size + strlen(data)) {
		pbuffer_grow(buffer, buffer->size + strlen(data));
	}
	memcpy((buffer->data + (size)), data, strlen(data));
}

ssize_t pbuffer_grow(pbuffer *buffer, ssize_t size)
{
	buffer->data = realloc(buffer->data, size);
	if (buffer == NULL) {
		printf("error\n");
		return(0);
	}
	buffer->size = size;
	return(size);
}

void pbuffer_free(pbuffer *buffer)
{
	if (buffer->data != NULL) {
		free(buffer->data);
	}
	if (buffer) {
		free(buffer);
	}
}
