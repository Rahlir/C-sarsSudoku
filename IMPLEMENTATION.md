
C-SarSudoku Implementation Spec
==========================

Blake Danziger, Tracey Mills, Tadeas Uhlir
May 2020
---------

## main

### Returns:

 - 0 if successfully creates or solves grid
 - 1 if incorrect arg number
 - 2 if unable to allocate memory for grid
 - 3 if arg is not "solve" or "create"
 - 4 if solve mode and invalid input from stdin

### Pseudocode

`main` validates and parses user input, and initializes either `creator` or `slver` module as indicated by input. It prints the output of these modules.

When `./sudoku mode` is run from the command line:
1. Checks that one argument is passed, returning error otherwise
2. Allocates memory for sudoku grid as an array of size 81
3. If mode is "create":
    1. Initializes each element of grid array to 0
    2. Calls `creator()` with grid, grid size as args
4. If mode is "solve":
    1. Calls `process_input()` function to read from stdin
        1. Reads 81 ints from stdin and stores them in grid
        2. Returns true if 81 ints saved to grid, false otherwise
    2. If `process_input()` returns false, returns error
    3. Otherwise, initializes `solver()` and stores int returned by solver
    	1. If 0, prints message indicating unique solution found
        2. If 1, prints message indicating multiple soluions foumd
        3. If 2, prints message indicating no solutions found
5. If mode is neither "create" nor "solve", frees grid and returns error
6. If mode is create or mode is solve and `solver()` did not return 2:
    1.  Prints grid line by line with whitespace between each int to stdout
7. Frees grid
8. Returns 0, indicating success


## creator

the `creator` module uses an array of integers to represent the sudoku grid. `creatr` is called in the `main` method of `sudoku.c` when in create mode.

When `creator` is called:
1. Checks that passed grid size is 81, does nothing if not
2. Calls `fill_grid()`, passing the given grid, field number 0, and the grid size
    1. `fill_grid()` returns 0 if the field number is not less than size
    2. Otherwise, it sets start to a random int 1-9 using `get_random()`
    3. It sets value to start
    4. It then enters a loop where it:
        1. Checks the consistency of value in the given field using the `check_consistency()` function as defined in common
        2. If consistent:
            1. It sets the given field in the given grid to value
            2. Recursively calls `fill_grid()` with the updated grid and field+1
            3. If this call returns 0, it breaks out of the loop
            4. Otherwise, it sets field in grid back to 0
        3. If not consistent:
            1. Increments value, going from 9 to 1
            2. If value is equal to start, indicating that no values work in that field, it returns 1
    5. After breaking out of the loop, it returns 0
    6. Once the first call to `fill_grid()` returns, all fields will be filled
3. Calls `remove_fields()`, passing the grid now containing a valid filled sudoku grid
  



## solver

#### Returns:

 - 0 if found only one solution to the puzzle
 - 1 if more than one solution to the puzzle
 - 2 if found no solutions to the puzzle
 - 3 if invalid grid size

### Pseudocode

the `solver` module uses an array of integers to represent the sudoku grid. `solver` is called in the `main` method of  `sudoku.c` when in solve mode.

When `solve()` is called:
1. First checks if the inputted size is 81. If the size is not 81 the program returns an error and doesn't run.
2. The first slot in the solution array is set to 0, to signal that it does not have a solution in it yet
2. Then initiates the helper function `solve_helper` to start the recursion.
3. `solve_helper` takes a pointer to an integer array that holds the unsolved grid, an integer array that is where the solution will be copied, the size of the grid, and the field in the grid that the helper function is looking at.
4. `solve_helper` starts at the given field and increments aross the grid until it finds the next 0 which is the next unsolved field.
5. Then for each number 1-9:
    1. check if putting the number in this cell is a legal move using the `check_consistent` function defined in `check.h` the `common` module.
    2. If the number can't go here, move on to the next digit.
    3. If the number can go here, add it to the array in this spot, and then recurse deeper by running `solve_helper` on the next grid space.
6. The program leaves the `solver_helper` function in the following situations:
    1. When the recursion gets to the end of the grid (the field incrementer reaches the size of the array) if solution array has a zero in its first slot, this is the first found solution, so the solution in the grid is copied to the solution grid using the local function `grid_copy` which loops through all values in the array and copies each one to the corresponding index in the solutions array. The function then exits to the previous depth, backtracing back to the last square and continuing the recursion to find another solution.
    2. if the end of the grid is reached and there is not a '0' in the first slot of the solution array, this means that we have found a second solution, and the helper function exits with code 2. The function checks for exit code 2, and if it finds it the previous level also returns 2. So once this second solution is found, the function completely backs out of the recursion and signals to `solve` that multiple solutions were found with its exit code of 2.
    3. If the loop of checking values 1-9 reaches the end, it means that no numbers work in that spot and the function must backtrace. To do this, the current grid space is set to 0 to signal that it still needs to be solved and the function simply returns 0 to get back to the previous depth where the next value for that field will be checked.
    4. If the first depth exits with code 0, this means that we have checked all possible numbers and the function returns 0.
6. If `solve_helper` returns 2, this means that multiple solutions were found
7. if `solver_helper` returns 0 it means that the function checked all possible answers. The first slot in the solutions grid is checked to see if a solution was found. If this cell is still 0, no solution was found and `solve` retuns with exit code 2. If this slot is not 0, then a single solution was found.
