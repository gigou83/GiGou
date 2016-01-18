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
	@$(CC) -L. -dynamiclib -install_name libaac.dylib -o libaac.dylib $(OBJ) -laaa
	mv libaac.dylib ../
	mv libaaa.dylib ../
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf *.dylib