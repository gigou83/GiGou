# GiGou/bin/kernel/thread/Makefile

.SUFFIXES:
.PHONY: clean

EXEC:kernel_thread
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS=-W -Wall -ansi

all: $(EXEC)

kernel_thread: $(OBJ)
	mv *.o UNIX/
	make -C UNIX
	mv libaac.dylib ../
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	make clean -C UNIX
	make clean -C WIN32
	@rm -rf *.o

mrproper: clean
	make mrproper -C UNIX
	make mrproper -C WIN32
	@rm -rf *.dylib