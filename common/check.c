/*  check.c file for C-SarSudoku
 *
 *  contains functions that are used to check a given puzzle
 *  see check.h for more information
 *
 *  Blake Danziger, Tracey Mills, Tadeas Uhlir
 *  CS 50, Spring 2020
 */

 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "check.h"

//////////////////// check_consistency ////////////////////
//returns true if value in field in grid is legal, false otherwise
bool check_consistent(int *grid, int field, int value) {
	int row = field/9;	//rows 0-8
	int col = field%9;	//cols 0-8
	int box_corner =(((int)(row/3))*27) + (((int)(col/3))*3);
	//check row
	for(int i=(row*9); i<row+9; i++) {
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

	return true;
}







