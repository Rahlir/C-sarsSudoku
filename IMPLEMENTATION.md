
C-SarSudoku Implementation Spec
==========================

Blake Danziger, Tracey Mills, Tadeas Uhlir
May 2020
---------

## main

## creator



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