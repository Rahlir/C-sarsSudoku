/*
 * creator - creates sudoku puzzles to be solved
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//creates grid
void creator(int *grid, int size);

//recursively fills valid sudoku grid, returns 1 on success and 0 on failure
int fill_grid(int *grid, int field, int size);

//returns random int min-max inclusive
int get_random(int min, int max);

