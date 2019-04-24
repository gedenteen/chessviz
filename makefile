COMP = g++
FLAGS = -Wall -Werror -c -std=c++11 -o
HEADERS = brd_out.h brd_read.h
objects = build/main.o build/brd_out.o build/brd_read.o

.PHONY: all clean install uninstall

all: bin/main

bin/main:	$(objects)
	$(COMP) $^ -o $@

build/main.o: src/main.cpp
	$(COMP) $(FLAGS) $@ $<

build/brd_read.o: src/brd_read.cpp
	$(COMP) $(FLAGS) $@  $<

build/brd_out.o: src/brd_out.cpp
	$(COMP) $(FLAGS) $@  $<

clean:
	rm -rf build/*.o all
