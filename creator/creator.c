/*
 * creator - creates sudoku puzzles to be solved
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int fill_grid(int *grid, int field, int size);
int get_random(int min, int max);
void remove_fields(int *grid, int n);


void creator(int *grid, int size) {
    //if(size == 81)    do we want to do this? should we even pass size or just assume its 81?
    //  I don't think this hurts -blake
    fill_grid(grid, 0, size);
    //remove_fields(grid, n);
}

//fills grid value by value using backtracking
int fill_grid(int *grid, int field, int size) {
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

//returns random int between min and max inclusive
int get_random(int min, int max) {
    srand(time(0));
    return (rand()%(max-min+1))+min;
}

//this does not work yet lol just some thoughts
/*
//removes n fields from completed grid such that it has a unique solution
void remove_fields(int *grid, int n) {
        remove_helper(grid, get_random(0, 80), 0, 40);
}

int remove_helper(int *grid, int field, int removed, int goal) {
        if(removed >= goal) {
                return 0;
        }
        int value = *(grid+field);
        //check if already removed
        if(value == 0) {
                remove_helper(grid, get_random(0, 80), removed, goal);
        }
        else {
                *(grid+field) = 0;
                if(solver(grid, 81)) {
                        while(remove_helper(grid, get_random(0, 80), removed+1, goal) == 0) {
                                return 0;
                        }
                        else {
                                
                        }
                }
        }
}
*/
