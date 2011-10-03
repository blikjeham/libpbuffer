# libbuffer Makefile

.SUFFIXES:
.SUFFIXES: .c .o

DEBUG = -ggdb
CFLAGS = -Wall -c -fPIC $(DEBUG)
LFLAGS = -shared -Wl,-soname,libpbuffer.so.1 $(DEBUG)

DEPS = pbuffer.h
OBJ = pbuffer.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

all: libpbuffer.so.1

libpbuffer.so.1: $(OBJ)
	$(CC) $(LFLAGS) -o $@ $^

.PHONY: clean all

clean:
	\rm -f *.o *.so* *~