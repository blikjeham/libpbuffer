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

#ifndef HAVE_PBUFFER_H
#define HAVE_PBUFFER_H 1

#include <stdlib.h>
#include <sys/types.h>

#define PBUFFER_MIN 120

#define pbuffer_end(a) (a->data + a->length)
#define pbuffer_start(a) (a->data = a->start)
#define pbuffer_unused(a) (a->allocated - a->length)

typedef struct pbuffer pbuffer;

struct pbuffer {
	size_t length;
	size_t allocated;
	void *start;
	void *data;
};

/* Allocate memory for the buffer. Return the pointer to the buffer. */
pbuffer *pbuffer_init(void);

/* Set the buffer to this value. */
void pbuffer_set(pbuffer *, void *, size_t );
int pbuffer_strcpy(pbuffer *, char *);

/* Add this string to the buffer. */
void pbuffer_add(pbuffer *, void *, size_t );
int pbuffer_strcat(pbuffer *, char *);

/* Move the begin */
void pbuffer_shift(pbuffer *, size_t );

/* Assure size of the buffer */
int pbuffer_assure(pbuffer *, size_t );

/* Grow the buffer to this new size */
size_t pbuffer_grow(pbuffer *, size_t );

/* Free the buffer data and the buffer itself. */
void pbuffer_free(pbuffer *);

#endif /* HAVE_PBUFFER_H */
