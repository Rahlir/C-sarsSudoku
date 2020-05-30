
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

    printf("%d\n", checker_consistency(grid, 0, 0));
    printf("%d\n", checker_consistency(grid, 0, 1));


    return 0;
}