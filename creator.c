/*
 * creator - creates sudoku puzzles to be solved
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void creator(int *grid, int size) {
	//if(size == 81)    do we want to do this? should we even pass size or just assume its 81?
	fill_grid(grid, 0, size);
	remove_fields(grid);

}

//fills grid value by value using backtracking
int fill_grid(int *grid, int field, int size) {
	if(field >= size)
		return 0;
	int start = get_random();
	int value = start;
	//find value that works
	while(true) {
		//check if value fits
		if(check_consistency(grid, field, value)) {
			*(grid+field) = value;
			//break out of loop if next field works
			if(fill_grid(grid, field+1, size) == 0)
				break;
			else
				*(grid+field) = 0;
		}
		//if value doesn't fit or makes it so no future solution...
		value = (value%9)+1;	//iterate value
		if(value == start)      //no values work
			return 1;       //go back and change previous
	}
	return 0;
}

//returns true and inserts value into grid if value in field in grid is legal, false otherwise
bool check_consistency(int *grid, int field, int value) {
	int row = field/9;	//rows 0-8
	int col = field%9;	//cols 0-8
	int box_corner =(((int)(row/3))*27) + (((int)(col/3))*3);
	//check row
	for(int i=row; i<row+9; i++) {
		if((i != field) && (*(grid+i) == value))
			return false;
	}
	//check col
	for(int i=col; i<(col+73); i+=9) {
		if((i != field) && (*(grid+i) == value))
                        return false;
	}
	//check box
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			int check = (box_corner+i)+(j*9);
			if((check != field) && (*(grid+check) == value))
                        	return false;
		}
	}
	*(grid+field) = value;
	return true;
}

int get_random() {
	return 1;
}
