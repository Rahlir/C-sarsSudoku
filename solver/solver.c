/*  solver.c file for C-SarSudoku
 *
 *  contains functions that are used to solve sudoku puzzles
 *  see solver.h for more information
 *
 *  Blake Danziger, Tracey Mills, Tadeáš Uhlíř
 *  CS 50, Spring 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "solver.h"
#include "check.h"
#include "utils.h"

/*---------------------------------prototypes---------------------------------*/

int solve_helper(int *grid, int *soln, int size, int field);

/*---------------------------------functions----------------------------------*/

//////////////////// solver ////////////////////
/* brute-force solves the puzzle, uses solve_helper to help with recursion
 * returns:
 * 0 if found only one solution,
 * 1 if more than one solution,
 * 2 if found no solutions
 * 3 if the inputted grid is already inconsistent or contains invalid values
 */
int solver(int *grid, int size)
{
    // check that grid is valid
    if (!check_valid(grid)) { // grid inconsisent or contains invalid values
        return 3;
    }
    //      creates a solutions array and sets the first number in the array to 0
    //              to signal that it does not yet contain a soltion
    int *soln = malloc(size * sizeof(int));
    if (soln == NULL) {
        printf("Error: memory error creating solution grid\n");
        return 4;
    }
    *soln = 0;

    if (solve_helper(grid, soln, size, 0) == 0) { // checked all numbers
        if (*(soln) == 0) {     // empty solution grid means no solutions
            grid_copy(soln, grid, size);
            free(soln);
            return 2;
        }
        else {  // non-empty solution grid means one solution
            grid_copy(soln, grid, size);
            free(soln);
            return 0;
        }
    }
    else {  // if return code is not 0, found second solution
        grid_copy(soln, grid, size);
        free(soln);
        return 1;
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
    while ((*(grid+i) != 0) && (i + 1 < size)) { // increment until i is at a 0 in the grid
        i++;
    }

    // check all numbers
    for (int j = 1; j < 10; j++) { // try all numbers 1-9
        if (check_consistency(grid, i, j)) {   // if number works, insert value and recurse deeper
            *(grid+i) = j;
            if (solve_helper(grid, soln, size, i+1) == 2) {
                // if found second solution, 2 is returned
                // break out of recursion
                return 2;
            }
        }
    }
    // have typed in all 9 numbers
    // need to backtrace: set cell to 0 to signal it as needing solving again
    // return 0 to ignal a backtrace and end of numbers
    *(grid+i) = 0;

    return 0;
}
