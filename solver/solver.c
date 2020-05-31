/*  solver.c file for C-SarSudoku
 *
 *  contains functions that are used to solve sudoku puzzles
 *  see solver.h for more information
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "solver.h"
#include "check.h"

//////////////////// local functions ////////////////////
int solve_helper(int *grid, int *soln, int size, int field);
int grid_copy(int *from, int *to, int size);

//////////////////// grid_copy ////////////////////
/*	copies one grid into another
 *	assumes both grids have the the same size
 */
int grid_copy(int *from, int *to, int size)
{ 
	for (int i = 0; i < size; i++) {
		*(to+i) = *(from+i);
	}

	return 0;
}

//////////////////// solve_now ////////////////////
// brute-force solves the puzzle, uses solve_helper to help with recursion
// 
// returns true if it's the only solution, false if more than one solution
int solve_now(int *grid, int *soln, int size)
{
    if (size != 81) {
        return 1;   // invalid grid size
    }

    
	if (solve_helper(grid, soln, size, 0) == 0) { // checked all numbers
		if (*(soln) == 0) { // empty solution grid means no solutions
		printf("No solutions found\n");
			return 0;
		}
		else { // non-empty solution grid means one solution
			printf("One solution found\n");
			return 1;
		}
	}
	else { // if return code is not 0, found second solution
		printf("Multiple solutions found\n");
			return 2;
	}
}


//////////////////// solve_helper ////////////////////
// recursive helper function for solve_now
int solve_helper(int *grid, int *soln, int size, int field)
{
    if (field == size) { // if reach the end
		// check if soln already in grid
		if (*(soln) == 0) { // no solution saved yet
			grid_copy(grid, soln, size);
			return 1;
		}
		else { //solution already saved
			// keep first solution but signal found second solution and end recursion
			return 2;
		}
        
    }

    int i = field;
    while (*(grid+i) != 0) { // increment until i is at a 0 in the grid
        i++;
    }


    // check all numbers
    for (int j = 1; j < 10; j++) { // try all numbers 1-9
		//printf("field: %d	try: %d\n", i, j);


        if (check_consistent(grid, i, j)) {   // if number works, insert value and recurse deeper
			//printf("works!\n");
			*(grid+i) = j;
			if (solve_helper(grid, soln, size, i+1) == 2) {
				// if found second solution, 2 is returned
				// break out of recursion
				return 2;
			}
			//printf("back!\n");
        }
    }
    // have typed in all 9 numbers
	// need to backtrace: set cell to 0 to signal it as needing solving again
	// return 0 to ignal a backtrace and end of numbers
	*(grid+i) = 0;

	return 0;
}
