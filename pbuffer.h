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

/* the minimum size of a pbuffer */
#define PBUFMIN 32

pbuffer *pbuffer_new(void);

void pbuffer_set(pbuffer *, char *);

void pbuffer_add(pbuffer *, char *);

ssize_t pbuffer_grow(pbuffer *, ssize_t );

void pbuffer_free(pbuffer *);

#endif /* HAVE_PBUFFER_H */
