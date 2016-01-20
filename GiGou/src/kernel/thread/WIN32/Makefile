# GiGou/bin/kernel/thread/WIN32/Makefile


#A ECRIRE COMME IL FAUT !!!

.SUFFIXES:
.PHONY: clean

EXEC:kernel_thread_WIN32
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS=-W -Wall -ansi

all: $(EXEC)

kernel_thread_WIN32: $(OBJ)
	mv *.o ../

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf *.dylib
	make clean