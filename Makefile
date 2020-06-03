# Makefile for C-SarSudoku
# Compiles sudoku.c and the other modules
# Libraries (common) have to be compiled separately
# Blake Danziger, Tracey Mills, Tadeáš Uhlíř
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
TESTPROG = sudoku-test
TEST = -DUNITTEST
TESTOBJS = sudoku.c $(SO)/solver.o $(CR)/creator.o 
TESTFLAGS =  -Wall -pedantic -std=c11 -ggdb -I$(CO) -I$(CR) -I$(SO)

############## make main program ##############

$(PROG): $(OBJS) $(CLIBS)
	$(CC) $(CFLAGS) $^ $(CLIBS) -o $@


############## make test program ##############

$(TESTPROG): $(TESTOBJS)
	$(CC) $(CFLAGS) $(TEST) $^ $(CLIBS) -o $@


# Dependencies: object files depend on header files
creator/creator.o: $(CR)/creator.h 

solver/solver.o: $(SO)/solver.h

common/common.a: $(CO)/check.h $(CO)/utils.h
	$(MAKE) -C $(CO)

.PHONY: all clean valgrind test

all: common/common.a $(PROG) $(TESTPROG)

valgrind: all
	bash valgrind.sh

test: all
	./testing.sh > testing.out
	./sudoku-test >> testing.out

############## clean all  ##############
clean:
	$(MAKE) -C $(CO) clean
	rm -f *~ *.o
	rm -f creator/*.o solver/*.o
	rm -f core
	rm -f *core.*
	rm -f *.dSYM
	rm -f $(PROG)
	rm -f $(TESTPROG)
