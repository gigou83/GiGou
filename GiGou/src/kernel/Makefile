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
	mv libaaa.dylib thread/
	make -C thread
	mv libaaa.dylib lib/
	make -C lib
	@$(CC) -L. -dynamiclib -install_name libaa.dylib -o libaa.dylib $(OBJ) -laaa -laab -laac
	mv libaa.dylib ../../build/
	mv libaaa.dylib ../../build/
	mv libaab.dylib ../../build/
	mv libaac.dylib ../../build/
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o
	make clean -C mem
	make clean -C thread
	make clean -C lib

mrproper: clean
	@rm -rf *.dylib
	make mrproper -C mem
	make mrproper -C thread
	make mrproper -C lib