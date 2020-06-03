# !/bin/bash
  
# testing.sh - Testing file for sudoku module
#
# Blake Danziger, Tadeas Uhlir, Tracey Mills

testDir=testfiles

echo "Integration Testing of sudoku module"
echo ""
#Error cases
echo "These tests should fail:"
echo "Too few arguments..."
./sudoku
echo "Too many arguments..."
./sudoku create solve
echo "Invalid arg..."
./sudoku xyz
echo "Solving grid with too few ints:"
cat "$testDir"/error_grid1
cat "$testDir"/error_grid1 | ./sudoku solve
echo "Solving grid with non-int chars:"
cat "$testDir"/error_grid2
cat "$testDir"/error_grid2 | ./sudoku solve

##### THIS ERROR NOT CORRECT: IT STARTS READING FROM STANDARD INPUT
echo "Solving grid with out-of-range ints:"
cat "$testDir"/error_grid3
cat "$testDir"/error_grid3 | ./sudoku solve
#####
echo "Solving grid with no solution:"
cat "$testDir"/error_grid4
cat "$testDir"/error_grid4 | ./sudoku solve
echo "Solving pre-filled grid with no solution:"
cat "$testDir"/error_grid5
cat "$testDir"/error_grid5 | ./sudoku solve
echo ""
#Success cases
echo "These tests should succeed:"
echo "Solving valid pre-filled grid:"
cat "$testDir"/grid6
cat "$testDir"/grid6 | ./sudoku solve
echo "Solving grid with more than one solution:"
cat "$testDir"/grid7
cat "$testDir"/grid7 | ./sudoku solve
echo "Solving grid with unique solution:"
cat "$testDir"/grid8
cat "$testDir"/grid8 | ./sudoku solve
echo "Fuzz testing with 10 randomly generated valid grids:"
for i in {1..10}
do
	./sudoku create > "$testDir"/grid9
	echo "Unsolved grid:"
	cat "$testDir"/grid9
	echo "Solution:"
	./sudoku solve < "$testDir"/grid9
	echo ""
	sleep 1
done

