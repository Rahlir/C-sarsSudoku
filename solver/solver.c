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
bool solve_helper(int *grid, int size, int field);

//////////////////// solve_now ////////////////////
// brute-force solves the puzzle, uses solve_helper to help with recursion
// 
// returns true if it's the only solution, false if more than one solution
int solve_now(int *grid, int size)
{
    if (size != 81) {
        return 1;   // invalid grid size
    }

    int i = 0;

    solve_helper(grid, size, i);

    }
    

    return 0;
}


//////////////////// solve_helper ////////////////////
// recursive helper function for solve_now
bool solve_helper(int *grid, int size, int field)
{
    int i = field;
    while (*(grid+i) != 0) { // increment until i is at a 0 in the grid
        i++;
    }

    // check all numbers
    for (int j = 1; j < 10; j++) { // try all numbers 1-9

        if (check_consistent(grid, i, j)) {   // if number works, insert value and recurse deeper
                *(grid+i) = j
                solve_helper(grid, size, i+i);
        }
    }
    // have typed in all 9 numbers


    // add check for being done (i == 80)
    // add check for end of numbers (go back)


    return true;
}
