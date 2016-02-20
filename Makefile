CC=gcc
CFLAGS=-Wall -g -std=c99 -lbsd

objs = 01

all: $(objs)

clean:
	rm -f $(objs)
