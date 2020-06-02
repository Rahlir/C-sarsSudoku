/*  creator.c file for C-SarSudoku
 *
 *  contains functions that are used to create sudoku puzzles
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */

#ifndef __CREATOR_H_
#define __CREATOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

///////////// creator ////////////////
/* recieves grid to be filled, along with its size
 * calls other functions to fill grid to make a uniqely
 * solvable sudoku puzzle
 */
void creator(int *grid, int size);

#endif /* ifndef __CREATOR_H_ */
