/*  creator.c file for C-SarSudoku
 *
 *  contains functions that are used to create sudoku puzzles
 *  see creator.h for more info
 *
 *  Blake Danziger, Tracey Mills, Tadeáš Uhlíř
 *  CS 50, Spring 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "creator.h"
#include "check.h"
#include "solver.h"
#include "utils.h"

/*------------------------------static variables------------------------------*/

// Static variable used to indicate whether srand(time(0)) was called
static bool RAND_INIT = false;

/*---------------------------------prototypes---------------------------------*/

////////////// fill_grid ///////////////
/* recieves grid to be filled, current field number to fill, and size of grid
 * recursively fills full valid sudoku grid using back-tracking
 * returns 1 on success and 0 on failue
 */
int fill_grid(int *grid, int field, int size);

////////////// get_random  ///////////////
/* returns random int in the range of min-max inclusive
 */
int get_random(int min, int max);

////////////// remove_fields  ///////////////
/* Receives filled grid from which values must be removed repeatedly
 * while ensuring that there is still a unique solution. Calls remove_helper
 * to achieve that
 */
void remove_fields(int *grid, int n, int size);

///////////// remove_helper ////////////////
/* Recursively removes random field from a pre-filled sudoku grid
 * and checks whether there is still unique solution to the puzzle.
 * Returns 0 on success and 1 on error
 */
int remove_helper(int *grid, int size, int field, int removed, int goal);

/*---------------------------------functions----------------------------------*/

void creator(int *grid, int size)
{
    fill_grid(grid, 0, size);
    remove_fields(grid, 40, size);
}

int fill_grid(int *grid, int field, int size)
{
    if(field >= size)
        return 0;
    int start = get_random(1, 9);
    int value = start;
    //find value that works
    while(true) {
        //check if value fits
        if(check_consistency(grid, field, value)) {
            *(grid+field) = value;
            //break out of loop if next field works
            if(fill_grid(grid, field+1, size) == 0) {
                break;
            }
            else {
                *(grid+field) = 0;
            }
        }
        //if value doesn't fit or makes it so no future solution...
        value = (value%9)+1;    //iterate value
        if(value == start) {      //no values work
            return 1;       //go back and change previous
        }
    }
    return 0;
}

int get_random(int min, int max)
{
    // srand(time(0)) must only be called once, otherwise we end up with
    // (mostly) the same random number everytime we call get_random()
    if (!RAND_INIT) {
        srand(time(0));
        RAND_INIT = true;
    }
    return (rand()%(max-min+1))+min;
}

//removes n fields from completed grid such that it has a unique solution
void remove_fields(int *grid, int n, int size)
{
    remove_helper(grid, size, get_random(0, size-1), 0, n);
}

int remove_helper(int *grid, int size, int field, int removed, int goal)
{
    // Successfully removed enough values
    if(removed >= goal) {
        return 0;
    }

    int original_value = *(grid+field);

    // Check if already removed
    if(original_value == 0) {
        return remove_helper(grid, size, get_random(0, size-1), removed, goal);
    }
    else {
        *(grid+field) = 0;

        // Need dummy_solution grid as this is passed to solver
        int *dummy_solution = calloc(size, sizeof(int));
        if (dummy_solution == NULL) {
            printf("Error: memory error creating solution grid\n");
            return 1;
        }

        grid_copy(grid, dummy_solution, size);

        if(solver(dummy_solution, size) == 0) {
            // Free allocated memory and return
            free(dummy_solution);
            return remove_helper(grid, size, get_random(0, size-1), removed+1, goal);
        }
        else {
            *(grid+field) = original_value;

            // Free allocated memory and return
            free(dummy_solution);
            return remove_helper(grid, size, get_random(0, size-1), removed, goal);
        }
    }
}
