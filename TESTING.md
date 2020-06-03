# TESTING for C-SarSudoku

## Blake Danziger, Tracey Mills, Tadeáš Uhlíř

## Spring 2020


Testing for C-SarSudoku is done in `testing.sh`, and the testing macro for `sudoku.c`

Running `make test` from the command line in the will run `testing.sh` script for integration testing and will compile and run the `sudoku-test` file that runs the testing scripts in `sudoku.c`. The output is saved to.....

## Description of `testing.sh`

`testing.sh` gets its webpage data from the files saved by `crawler`. The data used here is the crawler data from `http://old-www.cs.dartmouth.edu/~cs50/data/tse/wikipedia/` at a depth of 1. The path for this directory is `../crawler/data2`.

The index data is pulled from the indexfile at `../indexer/indexdata/index_2` which is the saved index for this set of webpages, created by `indexer`.


### First, tests `querier` with invalid argments



### Monkey testing with fuzzquery.c


