# Makefile Racine

.SUFFIXES:
.PHONY:

export CC=gcc
export CFLAGS=-W -Wall -ansi

LD=gcc
LDFLAGS=

all:
	make -C GiGou

clean:
	make clean -C GiGou

mrproper:
	make mrproper -C GiGou