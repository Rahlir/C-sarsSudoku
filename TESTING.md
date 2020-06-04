# TESTING for C-SarSudoku

## Blake Danziger, Tracey Mills, Tadeáš Uhlíř

## Spring 2020


Testing for C-SarSudoku is done in `testing.sh`, and the testing macro for `sudoku.c`

Running `make test` from the command line in the will run `testing.sh` script for integration testing and will compile and run the `sudoku-test` file that runs the testing scripts in `sudoku.c`. The output is saved to.....

Both `testing.sh` and the test code in `sudoku.c` pull test grid files from the `testfiles/` directory. This directory is stored under the name `testDir` in `testing.sh`.

## Description of Integration Testing with `testing.sh`

`testing.sh` is where re run our integration testing for C-sarSudoku. The script tests the following cases and saves the results to `testing.out`

### tests the main function and parameters

1. tries to run `./sudoku` with an incorrect number of arguments:

```bash
./sudoku
./sudoku create solve
```
These should produce errors, the code should not run and error messages should be read

2. tries to run the program with invalid arguments
```bash
./sudoku xyz
```
The program should terminate and should produce an error

### tests the sovle mode of C-sarSudoku

the grids that are tested are printed before each time the solver is run

1. tries to run `./sudoku solver` with a series of error-test grids that contain, respectively, too few integer elements, non-integer characters, and out of range integers (less than 0 or greater and 9)

```bash
cat "$testDir"/error_grid1 | ./sudoku solve
cat "$testDir"/error_grid2 | ./sudoku solve
cat "$testDir"/error_grid3 | ./sudoku solve
```
these should all return error and abort


2. runs `./sudoku solver` on an unsolved grid with no solutions and an already-filled grid that is inconsistent

```bash
cat "$testDir"/error_grid4 | ./sudoku solve
cat "$testDir"/error_grid5 | ./sudoku solve
```

the first command should run the solver which should find no solutions. The second command should abort with an error.

3. tests  `./sudoku solver` on a pre-filled consistent grid, an unsolved grid with multiple solutions, and an unsolved grid with one solution:

```bash
cat "$testDir"/grid6 | ./sudoku solve
cat "$testDir"/grid7 | ./sudoku solve
cat "$testDir"/grid8 | ./sudoku solve
```

should all run correctly and print a solution

### fuzz testing of the create and solve modes of C-sarSudoku

Generates 10 grids using `./solver create` which should be random since the create mode always generates a random grid. We noticed that when creating multiple grids in a row, the same grid was generated even though the program generates random grids. This is because when multiple grids are generated in a short period of time, the computer's timer does not change between calls and the computer's timer is the seed for generating the ranfom values, so we had to wait a second between each call of the creator.

For each grid, we run solve on it, each grid should be valid with a unique solution.


## Description of Unit Testing with `sudoku-test`

`./sudoku-test` is the version of `./sudoku` with the UNITTEST macro defined, which runs the test code of `main` instead of the regular code.

The program tests the functions `process_input`, `print_grid`, `check_consistency`, `check_valid`, and `grid_copy`.

The `solver` and `create` functions are thoroughly tested by the integration testing in `testing.sh` so they do not need to be tested here.

### `process_input and print_grid`
These functions are tested by passing in grids into the to see if they are read and repreinted correctly.

An empty grid and a consistent unsolved grid is passed, which should produce a `true` from `process_input` and then print correctly with `print_grid`. 

An inconsistent unsolved and an unsolved grid with out of range values are passed. Both should return false.

A valid grid with unevenly spaced elements in the file is passed into `process_input` which should return true and `print_grid` should print the grid with the standard shape.

Lastly, a grid containing some non-integers is passed in, which should return false

### `check_consistency`
We next check `check_consistency` by creating an integer array with all zeros except for 1-9 printed in order in the first 9 slots (corresponds to first row). it is then passed to `check_consistency` to check if it correctly checks the rows, columns, and squares by testing certain values in the same row, column, or square as another value. A valid and invalid value is tested for each.

### `check_valid`
`check_valid` checks the whole grid, so it is tested by creating integer arrays with out of range integers and then in-range integers. The function is run on both and should get false then true.

### `grid_copy`
tested by creating two grids, one with values and one with all zeros. Then the values in the first grid are copied into the second, both grids should be the same when both are printed.