CC=gcc
CFLAGS=-Wall -g -std=c99 -lbsd

objs = 01 02
objs += die.o

all: $(objs)

02: die.o

clean:
	rm -f $(objs)
