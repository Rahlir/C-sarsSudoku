# Makefile for 'common' module for C-SarSudoku
# 
# Blake Danziger, Tracey Mills, Tadeas Uhlir
# CS 50, Spring 2020


CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb
OBJS = check.o
MAKE = make
LIB = common.a

# Build the library by archiving object files
$(LIB): $(OBJS)
	ar cr $(LIB) $^

# Dependencies: object files depend on header files
check.o: check.h

.PHONY: all clean

all: $(LIB) check.o

clean:
	rm -f *~ *.o
	rm -f core
	rm -f *core.*
	rm -f $(LIB)
	rm -f *.dSYM