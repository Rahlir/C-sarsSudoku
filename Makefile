# Makefile for C-SarSudoku
# compiles sudoku.c and the other modules
# Blake Danziger, Tracey Mills, Tadeas Uhlir
# CS 50, Spring 2020


CC = gcc
CO = ./common
CR = ./creator
SO = ./solver
PROG = sudoku
OBJS = sudoku.o $(SO)/solver.o $(CR)/creator.o $(CO)/check.o $(CO)/common.a
CFLAGS = -Wall -pedantic -std=c11 -ggdb -I$(CO) -I$(CR) -I$(SO)
CLIBS = $(CO)/common.a
MAKE = make


############## make main program ##############

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@


# Dependencies: object files depend on header files
common/check.o: $(CO)/check.h

common/common.a: $(CO)/check.h
	$(MAKE) -C $(CO)

creator/creator.o: $(CR)/creator.h $(CO)/check.h

solver/solver.o: $(SO)/solver.h $(CO)/check.h

.PHONY: all clean

all: $(PROG) 

############## clean all  ##############
clean:
	rm -f *~ *.o
	rm -f */*.o
	rm -f core
	rm -f *core.*
	rm -f $(PROG)
	rm -f *.dSYM
	$(MAKE) -C $(CO) clean
