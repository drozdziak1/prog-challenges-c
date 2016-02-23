CC=gcc
CFLAGS=-Wall -std=c99 -lbsd -lm

objs = 01 02 03
objs += die.o

all: CFLAGS += -g
release: CFLAGS += -O2


all: $(objs)

release: $(objs)

02: die.o

03: die.o

clean:
	rm -f $(objs)
