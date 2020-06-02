# Makefile for C-SarSudoku
# Compiles sudoku.c and the other modules
# Libraries (common) have to be compiled separately
#
# Blake Danziger, Tracey Mills, Tadeas Uhlir
# CS 50, Spring 2020

CC = gcc
CO = ./common
CR = ./creator
SO = ./solver
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(CO) -I$(CR) -I$(SO)
CLIBS = $(CO)/common.a
MAKE = make

PROG = sudoku
OBJS = sudoku.o $(SO)/solver.o $(CR)/creator.o 

############## make main program ##############

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(CLIBS) -o $@


# Dependencies: object files depend on header files
creator/creator.o: $(CR)/creator.h 

solver/solver.o: $(SO)/solver.h

.PHONY: all clean valgrind test

all: $(PROG) 

valgrind: all
	bash valgrind.sh

test: all
	bash testing.sh

############## clean all  ##############
clean:
	$(MAKE) -C $(CO) clean
	rm -f *~ *.o
	rm -f creator/*.o solver/*.o
	rm -f core
	rm -f *core.*
	rm -f *.dSYM
	rm -f $(PROG)
