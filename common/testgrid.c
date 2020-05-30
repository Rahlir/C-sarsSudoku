
#include<stdlib.h>
#include<stdio.h>

#include "check.h"




// create test grid
int main()
{
    int size = 81;

    int *grid = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        *(grid+i) = 0;
    }

    printf("%d\n", check_consistent(grid, 45, 0));
    printf("%d\n", check_consistent(grid, 21, 1));
    printf("%d\n", check_consistent(grid, 45, 0));
    printf("%d\n", true);


    return 0;
}