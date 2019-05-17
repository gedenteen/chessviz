COMP = gcc
FLAGS = -Wall -Werror -std=gnu11 -MMD -c -o
HEADERS = brd_out.h brd_read.h
objects = build/src/main.o build/src/brd_out.o build/src/brd_read.o
INCLUDE = -I thirdparty -I src

.PHONY: all clean test

all: bin/chessviz

bin/chessviz:	$(objects)
	$(COMP) -o $@ $^

build/src/main.o: src/main.c
	$(COMP) $(FLAGS) $@ $<

build/src/brd_read.o: src/brd_read.c
	$(COMP) $(FLAGS) $@ $<

build/src/brd_out.o: src/brd_out.c
	$(COMP) $(FLAGS) $@ $<

test: bin/chessviz-test

bin/chessviz-test: build/test/main.o build/test/brd_read.o build/test/brd_test.o
	$(COMP) -o $@ $^

build/test/main.o: test/main.c
	$(COMP) $(INCLUDE) $(FLAGS) $@ $<

build/test/brd_test.o: test/brd_test.c
	$(COMP) $(INCLUDE) $(FLAGS) $@ $<

build/test/brd_read.o: src/brd_read.c
	$(COMP) $(INCLUDE) $(FLAGS) $@ $<

clean:
	rm -rf build/src/*.o build/src/*.d build/test/*.o built/test/*.d
