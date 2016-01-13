# GiGou/bin/kernel/Makefile

.SUFFIXES:
.PHONY: clean

EXEC:kernel
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS=-W -Wall -ansi

all: $(EXEC)

kernel: $(OBJ)
	make -C mem
	@$(CC) -L. -dynamiclib -install_name libaaa001.dylib -o libaaa001.dylib $(OBJ) -laba001
	mv libaba001.dylib ../../build/
	mv libaaa001.dylib ../../build/
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o
	make clean -C mem

mrproper: clean
	@rm -rf libaaa001.dylib
	@rm -rf libaba001.dylib
	make mrproper -C mem