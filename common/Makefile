# Makefile for 'common' module for C-SarSudoku
# 
# Blake Danziger, Tracey Mills, Tadeas Uhlir
# CS 50, Spring 2020

OBJS = check.o utils.o
LIB = common.a

CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb
MAKE = make

# Build the library by archiving object files
$(LIB): $(OBJS)
	ar cr $@ $^

# Dependencies: object files depend on header files
check.o: check.h

utils.o: utils.h

.PHONY: all clean

all: $(LIB) check.o

clean:
	rm -f *~ *.o
	rm -f core
	rm -f *core.*
	rm -f *.dSYM
	rm -f $(LIB)
