/*  check.c file for C-SarSudoku
 *
 *  contains functions that are used to check a given puzzle
 *  see check.h for more information
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */

 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "check.h"




//////////////////// local_functions ////////////////////
bool check_row(int *grid, int index, int test_value);
bool check_column(int *grid, int index, int test_value);
bool check_square(int *grid, int index, int test_value);



//////////////////// notes ////////////////////
// 81 grid spaces, indeces 0-80
// find row by integer dividing by 9
// find column by modding by 9

//////////////////// check_row ////////////////////
/*  Given a grid, an index (location in the grid), and a value,
 *      checks if the value works in the row
 */
bool check_row(int *grid, int index, int test_value)
{
    return true;
}

//////////////////// check_column ////////////////////
/*  Given a grid, an index (location in the grid), and a value,
 *      checks if the value works in the row
 */
bool check_column(int *grid, int index, int test_value)
{
    return true;
}

//////////////////// check_square ////////////////////
/*  Given a grid, an index (location in the grid), and a value,
 *      checks if the value works in the row
 */
bool check_square(int *grid, int index, int test_value)
{
    return true;
}



//////////////////// check ////////////////////
/*  Given a grid, an index (location in the grid), and a value
 *      checks if the value works in the given space
 *
 */
bool check(int *grid, int index, int test_value)
{
    if (!check_row(grid, index test_value))
        return false;

    if (!check_column(grid, index test_value))
        return false;

    if (!check_square(grid, index test_value))
        return false;

    return true;
}






