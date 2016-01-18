# GiGou/bin/kernel/lib/Makefile

.SUFFIXES:
.PHONY: clean

EXEC:kernel_lib
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS=-W -Wall -ansi

all: $(EXEC)

kernel_lib: $(OBJ)
	@$(CC) -L. -dynamiclib -install_name libaab.dylib -o libaab.dylib $(OBJ) -laaa
	mv libaaa.dylib ../
	mv libaab.dylib ../
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf *.dylib