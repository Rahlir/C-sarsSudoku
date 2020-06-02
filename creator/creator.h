/*  creator.c file for C-SarSudoku
 *
 *  contains functions that are used to create sudoku puzzles
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

///////////// creator ////////////////
/* recieves grid to be filled, along with its size
 * calls other functions to fill grid to make a uniqely solvable sudoku puzzle
 */
void creator(int *grid, int size);

////////////// fill_grid ///////////////
/* recieves grid to be filled, current field number to fill, and size of grid
 * recursively fills full valid sudoku grid using back-tracking
 * returns 1 on success and 0 on failue
 */
int fill_grid(int *grid, int field, int size);

////////////// remove_fields  ///////////////

////////////// get_random  ///////////////
//returns random int min-max inclusive
int get_random(int min, int max);
