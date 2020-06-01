# !/bin/bash
  
# testing.sh - Testing file for sudoku module
#
# Blake Danziger, Tadeas Uhlir, Tracey Mills

echo "Testing sudoku module"
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
cat errorGrid1
cat errorGrid1 | ./sudoku solve
echo "Solving grid with non-int chars:"
cat errorGrid2
cat errorGrid2 | ./sudoku solve
echo "Solving grid with out-of-range ints:"
cat errorGrid3
cat errorGrid3 | ./sudoku solve
echo "Solving grid with no solution:"
cat errorGrid4
cat errorGrid4 | ./sudoku solve
echo "Solving pre-filled grid with no solution:"
cat errorGrid5
cat errorGrid5 | ./sudoku solve
echo ""
#Success cases
echo "These tests should succeed:"
echo "Solving valid pre-filled grid:"
cat grid6
cat grid6 | ./sudoku solve
echo "Solving grid with more than one solution:"
cat grid7
cat grid7 | ./sudoku solve
echo "Fuzz testing with 10 randomly generated valid grids:"
for i in {1..10}
do
	./sudoku create > grid8
	echo "Unsolved grid:"
	cat grid8
	echo "Solution:"
	./sudoku solve < grid8
	echo ""
done

