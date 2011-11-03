/*
 * libpbuffer - dynamic buffer handling in C
 * Copyright (c) 2011 Wybe van der Ham
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "pbuffer.h"

pbuffer *pbuffer_init(void)
{
	pbuffer *newbuffer;
	newbuffer = malloc(sizeof(ssize_t) + sizeof(char *));
	newbuffer->size = 0;
	newbuffer->data = malloc(0);
	return(newbuffer);
}

void pbuffer_set(pbuffer *buffer, char *data)
{
	if (buffer->size < strlen(data)) {
		if(!pbuffer_grow(buffer, strlen(data))) {
			fprintf(stderr, "growing pbuffer failed\n");
			return;
		}
	} else {
		/* If not grown, we need to set the size */
		buffer->size = strlen(data);
	}
	strncpy(buffer->data, data, strlen(data));
}

int pbuffer_strcpy(pbuffer *buffer, char *data)
{
	if (buffer->size < strlen(data)) {
		if (!pbuffer_grop(buffer, strlen(data))) {
			fprintf(stderr, "growing pbuffer failed\n");
			return(-1);
		}
	} else {
		buffer->size = strlen(data);
	}
	strncpy(buffer->data, data, strlen(data));
	return(0);
}

void pbuffer_add(pbuffer *buffer, char *data)
{
	ssize_t size;
	size = buffer->size;
	if (buffer->size < buffer->size + strlen(data)) {
		pbuffer_grow(buffer, buffer->size + strlen(data));
	} else {
		buffer->size = buffer->size + strlen(data);
	}
	memcat((buffer->data + (size)), data, strlen(data));
}

int pbuffer_strcat(pbuffer *buffer, char *data)
{
	ssize_t size;
	size = buffer->size;
	if (buffer->size < buffer->size + strlen(data)) {
		pbuffer_grow(buffer, buffer->size + strlen(data));
	} else {
		buffer->size = buffer->size + strlen(data);
	}
	
	strncpy((buffer->data + (size)), data, strlen(data));
	
	return(0);
}

ssize_t pbuffer_grow(pbuffer *buffer, ssize_t size)
{
	buffer->data = realloc(buffer->data, size);
	if (buffer->data == NULL) {
		printf("error reallocating memory.\n");
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
