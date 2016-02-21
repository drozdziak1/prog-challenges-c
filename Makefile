CC=gcc
CFLAGS=-Wall -std=c99 -lbsd

objs = 01 02 03
objs += die.o

all: CFLAGS += -g
release: CFLAGS += -O2


all: $(objs)

release: $(objs)

02: die.o

clean:
	rm -f $(objs)
