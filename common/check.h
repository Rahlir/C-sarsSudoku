/*  check.c file for C-SarSudoku
 *
 *  contains functions that are used to check a given puzzle
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */


#ifndef __CHECK_H
#define __CHECK_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//////////////////// check_consistency ////////////////////
/*  returns true if value in field in grid is legal, false otherwise
 *
 *  input a grid pointer, a field index, and a test value
 *
 *  assumes the grid has 81 slots and that the field is between 0 and 80
 *  assumes that value is from 1-9
 */
bool check_consistency(int *grid, int field, int value);








#endif