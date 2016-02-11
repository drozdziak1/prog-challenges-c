CC=gcc
CFLAGS=-Wall -g -std=c99

objs = 01

all: $(objs)

clean:
	rm -f $(objs)
