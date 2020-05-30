# Makefile for 'common' module for C-SarSudoku
# 
# Blake Danziger, Tracey Mills, Tadeas Uhlir
# CS 50, Spring 2020


CC = gcc
CFLAGS = -Wall -pedantic -std=c11 -ggdb
LIBS = 
PROG = testgrid
OBJS = testgrid.o check.o
MAKE = make


$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@


test.o: check.h

check.o: check.h

all: $(PROG)

.PHONY: all clean test valgrind

test: $(PROG)
	# ./testing.sh 2>&1 | tee testing.out


clean:
	rm -f *~ *.o
	rm -f core
	rm -f *core.*
	rm -f $(PROG)
	rm -f *.dSYM