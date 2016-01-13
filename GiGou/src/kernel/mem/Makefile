# GiGou/bin/kernel/mem/Makefile

.SUFFIXES:
.PHONY: clean

EXEC:kernel_mem
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS=-W -Wall -ansi

all: $(EXEC)

kernel_mem: $(OBJ)
	@$(CC) -dynamiclib -install_name libaba001.dylib -o libaba001.dylib $(OBJ)
	mv libaba001.dylib ../
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf libaba001.dylib