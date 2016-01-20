# GiGou/bin/kernel/thread/UNIX/Makefile

.SUFFIXES:
.PHONY: clean

EXEC:kernel_thread_UNIX
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS=-W -Wall -ansi

all: $(EXEC)

kernel_thread_UNIX: $(OBJ)
	@$(CC) -L. -dynamiclib -install_name libaac.dylib -o libaac.dylib $(OBJ) 
	mv libaac.dylib ../
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf *.dylib
	make clean