COMP = gcc
FLAGS = -Wall -Werror -std=gnu11 -MMD -c -o
HEADERS = brd_out.h brd_read.h
objects = build/main.o build/brd_out.o build/brd_read.o

.PHONY: all clean install uninstall

all: bin/main

bin/main:	$(objects)
	$(COMP) -o $@ $^

build/main.o: src/main.c
	$(COMP) $(FLAGS) $@ $<

build/brd_read.o: src/brd_read.c
	$(COMP) $(FLAGS) $@  $<

build/brd_out.o: src/brd_out.c
	$(COMP) $(FLAGS) $@  $<

clean:
	rm -rf build/*.o all
