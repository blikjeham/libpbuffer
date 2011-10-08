/*
 * pbuffer.h
 *
 *
 */

#ifndef HAVE_PBUFFER_H
#define HAVE_PBUFFER_H 1

#include <stdlib.h>

typedef struct pbuffer pbuffer;

struct pbuffer {
	ssize_t size;
	char *data;
};

/* Allocate memory for the buffer. Return the pointer to the buffer. */
pbuffer *pbuffer_new(void);

/* Set the buffer to this value. */
void pbuffer_set(pbuffer *, char *);

/* Add this string to the buffer. */
void pbuffer_add(pbuffer *, char *);

/* Grow the buffer to this new size */
ssize_t pbuffer_grow(pbuffer *, ssize_t );

/* Free the buffer data and the buffer itself. */
void pbuffer_free(pbuffer *);

#endif /* HAVE_PBUFFER_H */
