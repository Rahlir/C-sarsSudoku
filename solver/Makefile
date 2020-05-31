# Makefile for 'solvetest' file for C-SarSudoku
# 
# Blake Danziger, Tracey Mills, Tadeas Uhlir
# CS 50, Spring 2020


CC = gcc
C = ../common
PROG = solvetest
OBJS = solvetest.o solver.o $C/check.o
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$C
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


# Dependencies: object files depend on header files
solvetest.o: solvetest.c

solver.o: solver.h $C/check.h

../common/check.o: $C/check.h



.PHONY: all clean

all: $(PROG)

clean:
	rm -f *~ *.o
	rm -f core
	rm -f *core.*
	rm -f $(PROG)
	rm -f *.dSYM