/*  solver.c file for C-SarSudoku
 *
 *  contains functions that are used to solve sudoku puzzles
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */


 #include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



//////////////////// solve_now ////////////////////
// brute-force solves the puzzle, uses solve_helper to help with recursion
// 
// returns true if it's the only solution, false if more than one solution
int solve_now(int *grid, int *soln, int size);
