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
- 2: Given first argument pageDirectory not a valid, readable directory or memory error in checking pageDirectory
- 3: Given second argument indexFilename not a valid, readable regular file


### Assumptions

QUERIER

The querier assumes that the input directory and files follow the designated formats.

* `pageDirectory` has files named 1, 2, 3, ..., without gaps.
* The content of files in `pageDirectory` follow the format as defined in the specs; thus your code (to read the files) need not have extensive error checking.
* The content of the file named by `indexFilename` follows our the format as defined in the specs, being, most importantly for *querier*, that the URL is on line 1.

Assume were running `querier` on a system that recognizes pathnames with double slashes `//`
This way `queriuer` can be called with second parameter `pageDirectory` or `pageDirectory/`.
This assumption is met on the cs.dartmouth.edu linux servers



### Non-Assumptions

The *querier* malloc's the size of the word array to the large enough to handle the maximum number of words in an input line[bdanziger@moose ~/cs50/group_project/C-sarsSudoku]$ 

