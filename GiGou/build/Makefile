# GiGou/Makefile

.SUFFIXES:
.PHONY: clean

EXEC:test
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS=-W -Wall -ansi

all: $(EXEC)

test: $(OBJ)
	$(CC) -L. -o app $(SRC) -laaa001 -laba001
	make clean

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf app
	@rm -rf *.dylib