# GiGou/Makefile

.SUFFIXES:
.PHONY: clean

all:
	make -C src
	make -C build

clean:
	make clean -C src

mrproper: clean
	make mrproper -C build
	make mrproper -C src