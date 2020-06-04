/*  main module for C-sarSudoku
 *  sudoku.c - generates sudoku puzzles with unique solutions and solves sudoku puzzles
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "creator.h"
#include "solver.h"
#include "check.h"
#include "utils.h"

static const int SUDOKU_SIZE = 81;

void print_grid(int *grid, int size);
bool process_input(int *grid, int size, FILE *fp);

int main(int argc, char *argv[]) {
    #ifndef UNITTEST    // run normally if not testing

        char *mode;

        //check arg #
        if(argc != 2) {
            fprintf(stderr, "Error: provide one arg indicating mode\n");
            fprintf(stderr, "Usage: %s mode\n", argv[0]);
            return 1;
        }

        //allocate memory for grid
        int *grid = malloc(sizeof(int)*SUDOKU_SIZE);
        if(grid == NULL) {
            fprintf(stderr, "Error: unable to allocate memory for grid\n");
            return 2;
        }

        mode = argv[1];

        //create mode
        if(strcmp(mode, "create") == 0) {
            //initialize empty grid
            for(int i=0; i<SUDOKU_SIZE; i++) {
                *(grid+i) = 0;
            }
            //initialize creator
            creator(grid, SUDOKU_SIZE);
        }
        //solve mode
        else if(strcmp(mode, "solve") == 0) {
            //get puzzle to be solved
            if(process_input(grid, SUDOKU_SIZE, stdin)) {
                
                //initialize solver
                int return_code = solver(grid, SUDOKU_SIZE);
                
                if (return_code == 0) {
                    printf("Found unique solution:\n");
                }
                else if (return_code == 1) {
                    printf("Found multiple solutions, printing one:\n");
                }
                else if (return_code == 2) {
                    printf("Couldn't find any solutions\n");
                    free(grid);
                    return 4;
                }
                else if (return_code == 3) {
                    fprintf(stderr, "Error: invalid grid\n");
                    free(grid);
                    return 5;
                }
                else {
                    fprintf(stderr, "Error allocating memory\n");
                    free(grid);
                    return 2;
                }
            }
            else {
                fprintf(stderr, "Error: invalid grid\n");
                free(grid);
                return 5;
            }
        }
        //invalid mode
        else {
            fprintf(stderr, "Error: mode must be either 'create' or 'solve'\n");
            free(grid);
            return 3;
        }

        //print output if a solution was found
        print_grid(grid, SUDOKU_SIZE);

        free(grid);
        return 0;
    
    #endif  // end of not test

    #ifdef UNITTEST     // run test code if testing
    // print the test output to testing.out

        printf("UNIT TESTING\n");
    int *grid = malloc(sizeof(int)*SUDOKU_SIZE);
    if(grid == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for grid\n");
        return 2;
    }        

    /**************** Test functions in sudoku.c ****************/
    ///////////// process_input and print_grid/////////////
    printf("\n************** process_input and print_grid **************\n");
    printf("Test on empty grid (all 0s): first command should return true\nand print_grid should print an empty grid correctly\n");
    FILE *fp = fopen("testfiles/empty_grid", "r");
    printf(process_input(grid, SUDOKU_SIZE, fp) ? "true\n" : "false\n");
    print_grid(grid, SUDOKU_SIZE);
    fclose(fp);

    printf("\nClear the grid after each call\n");
    free(grid);
    grid = malloc(sizeof(int)*SUDOKU_SIZE);

    printf("\nTest on valid grid: first command should return true \nand print_grid should print correctly\n");
    fp = fopen("testfiles/unittest_grid10", "r");
    printf(process_input(grid, SUDOKU_SIZE, fp) ? "true\n" : "false\n");
    print_grid(grid, SUDOKU_SIZE);
    fclose(fp);

    printf("\nTest on an inconsistent grid with: should return false\n");
    fp = fopen("testfiles/unittest_grid11", "r");
    printf(process_input(grid, SUDOKU_SIZE, fp) ? "true\n" : "false\n");
    fclose(fp);

    printf("\nTest on grid with out of range values: should return false\n");
    fp = fopen("testfiles/unittest_grid12", "r");
    printf(process_input(grid, SUDOKU_SIZE, fp) ? "true\n" : "false\n");
    fclose(fp);


    printf("\nTest on valid grid but numbers are unevenly spaced across the file: \nshould return true and print grid normally\n");
    fp = fopen("testfiles/unittest_grid13", "r");
    printf(process_input(grid, SUDOKU_SIZE, fp) ? "true\n" : "false\n");
    print_grid(grid, SUDOKU_SIZE);
    fclose(fp);


    printf("\nTest on invalid grid with non-integers: \nshould return false\n");
    fp = fopen("testfiles/unittest_grid14", "r");
    printf(process_input(grid, SUDOKU_SIZE, fp) ? "true\n" : "false\n");
    fclose(fp);


    free(grid);


        /**************** Test functions in check.h ****************/
        ///////////// check_consistency /////////////
        printf("\n************** check_consistency **************\n");
	grid = malloc(sizeof(int)*SUDOKU_SIZE);
	for(int i=0; i<81; i++)
		*(grid+i) = 0;
	for(int i=0; i<9; i++)
		*(grid+i) = i+1;
	
	//check row
	printf("Test on row with repeat ints: \nshould return false\n");
	printf(check_consistency(grid, 0, 2) ? "true\n" : "false\n");
	printf("Test on row with no repeat ints: \nshould return true\n");
	printf(check_consistency(grid, 0, 1) ? "true\n" : "false\n");
	printf("\n");

	//check col
	printf("Test on col with repeat ints: \nshould return false\n");
        printf(check_consistency(grid, 9, 1) ? "true\n" : "false\n");
	printf("Test on col with no repeat ints: \nshould return true\n");
	printf(check_consistency(grid, 9, 5) ? "true\n" : "false\n");
	printf("\n");

	//check square
	printf("Test on square with repeat ints: \nshould return false\n");
        printf(check_consistency(grid, 9, 2) ? "true\n" : "false\n");
        printf("Test on square with no repeat ints: \nshould return true\n");
	printf(check_consistency(grid, 9, 5) ? "true\n" : "false\n");
	printf("\n");
	
	free(grid);

        ///////////// check_valid /////////////
        printf("\n************** check_valid **************\n");
	grid = malloc(sizeof(int)*SUDOKU_SIZE);
        for(int i=0; i<81; i++)
                *(grid+i) = 0;
	*(grid+7) = -3;
	*(grid+25) = 100;
	*(grid+59) = -2;
	
	//bad grid
	printf("Test on grid with out of range values, should return false:\n");
	print_grid(grid, 81);
	printf(check_valid(grid) ? "true\n" : "false\n");
	
	*(grid+7) = 3;
        *(grid+25) = 1;
        *(grid+59) = 7;

	//good grid
        printf("Test on grid with in range values, should return true:\n");
        print_grid(grid, 81);
        printf(check_valid(grid) ? "true\n" : "false\n");

	free(grid);

        /**************** Test functions in util.h ****************/
        ///////////// grid_copy /////////////
        printf("\n************** grid_copy **************\n");
	grid = malloc(sizeof(int)*SUDOKU_SIZE);
        for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
                	*(grid+(i*9)+j) = j+1;
	
	int *grid2 = malloc(sizeof(int)*SUDOKU_SIZE);
	for(int i=0; i<81; i++)
                *(grid2+i) = 0;

	printf("Grid1:\n");
	print_grid(grid, 81);
	printf("Grid2:\n");
        print_grid(grid2, 81);
	printf("Copying Grid1 to Grid2...\n");
	grid_copy(grid, grid2, 81);
	printf("Updated grid2:\n");
	print_grid(grid2, 81);

	free(grid);
	free(grid2);

    #endif  // end of test
}

/*
 * process_input reads user input and modifies the grid appropriately
 * reads n = "size" ints into grid, adding them in order
 * returns true if n = "size" ints read into grid, false otherwise
 */


bool process_input(int *grid, int size, FILE *fp)
{
    for(int i=0; i<size; i++) {
        if(fscanf(fp, "%d", (grid+i)) != 1) {	
            return false;
        }
    }
    // check that grid is valid
    if (!check_valid(grid)) { // grid inconsisent or contains invalid values
        return false;
    }
    return true;
}


/*
 * print_grid prints the numbers in the given array in a 9x9 grid to stdout.
 * If size != 81, it does nothing.
 * Otherwise, it prints the numbers line by line, with the first 9 numbers in the first line,
 * the second 9 numbers in the second line, and on until 9 lines have been printed.
 * Numbers are separated by a whitespace.
 */
void print_grid(int *grid, int size) {
    if(size == 81) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d ", *(grid+(i*9)+j));
            }
            printf("\n");
        }
    }
}
