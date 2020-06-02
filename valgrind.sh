#!/bin/bash

# valgrind.sh
# Script to check for memory leaks of C-sarSudoku
# program
#
# Blake Danziger, Tadeáš Uhlíř, Tracey Mills
# CS 50, Spring 2020 

valgrindCmd="valgrind --leak-check=full --show-leak-kinds=all"

echo "Checking for memory leaks in \"create mode\":"
eval "$valgrindCmd" ./sudoku create > valgrind_run.out

echo "--------------------------------------------------------------------------------"

echo "Checking for memory leaks in \"solve mode\":"
cat valgrind_run.out | eval  "$valgrindCmd" ./sudoku solve

echo
echo "Cleaning output files.."
rm -f valgrind_run.out
