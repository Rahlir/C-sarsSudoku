README for C-SarSudoku
==========================
Blake Danziger, Tracey Mills, Tadeáš Uhlíř

Spring 2020
---------

## sudoku
C-sarSudoku is a program that can create a randomized sudoku grid with a unique solution. The program can also be passed an unsolved grid and finds a solution to the puzzle.


### Compilation

To compile, simply run `make` from the command line within the main directory.

### Usage

Once compiled, run `sudoku` with 
``` bash
./sudoku mode
```
where `mode` is either going to be `create` or `solve`

### Testing

To test, simply enter `make test` from the command line in the main directory.
This runs the `testing.sh` script that runs integration testing. The `make test` command then compiles and runs the `sudoku-test` file that uses macros to run test code written in `sudoku.c`. The outputs are saved to the `testing.out` file.

Testing requires there to be a compiled `fuzzquery` file in teh directory. `fuzzquery` can be compiled from `fuzzquery.c` by running `make fuzzquery` from the command line within the `querier/` directory.

### Clean

enter `make clean` into the command line within the `querier/` directory to remove all object, executable, and core files that are created by the Makefile. You can also clean all modules by typing `clean` from the `tse-bdanziger3/` directory.


### exit codes:

- 0: Ran correctly without errors
- 1: Incorrect number of arguments
- 2: Unable to allocate memory for grid array
- 3: Unexpected arg
- 4: Solve mode, no solutions to given grid
- 5: Solve mode, invalid user input

### Assumptions
When inputting a grid into the solve mode, it is assumed that the grid is being passed in by alternating integer elements and whitespace characters.

### Non-Assumptions

* Many of the functions assume that they are being poassed a grid with size 81, but the process_input function only reads in grids that are of size 81. It reads the first 81 if given more and returns an error if given fewer elements.

* There are checks in place that produce errors if non-integers are passed and the input is still read correctly if elements are separated by more than one whitespace character.
