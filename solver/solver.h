/*  solver.c file for C-SarSudoku
 *
 *  contains functions that are used to solve sudoku puzzles
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */

#ifndef __SOLVER_H
#define __SOLVER_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//////////////////// solve ////////////////////
/* brute-force solves an unsolved sudoku grid
 * 
 * takes an integer array as an input that represents the valuse in the unsolved sudoku grid
 * zeros in the unsolved array represent fields that need to be solved
 *
 * takes as arguments:
 *		a pointer to an integer array representing the grid being solved
 *		a pointer to an empty integer where the solution will be saved
 *		the size of the grids
 * returns:
 *		0 if found only one solution
 *		1 if more than one solution
 *		2 if found no solutions
 *		3 if invalid grid size
 *
 * Assumes that grid inputs are the same size
 * The solver only runs if size is 81
 */
int solve(int *grid, int *soln, int size);

#endif
