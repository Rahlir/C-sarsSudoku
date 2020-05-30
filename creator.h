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

//returns true and inserts value into grid if value in field in grid is legal, false otherwise
bool check_consistency(int *grid, int field, int value);

//returns random int 1-9
int get_random();

