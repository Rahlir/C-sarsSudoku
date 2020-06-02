/*
 * -----------------------------------------------------------------------------
 * utils.c
 *
 * Implementation file for utils module
 *
 * Blake Danziger, Tracey Mills, Tadeáš Uhlíř
 * 2020/06/02 
 * -----------------------------------------------------------------------------
 */

#include "utils.h"

int grid_copy(int *from, int *to, int size)
{ 
    for (int i = 0; i < size; i++) {
        *(to+i) = *(from+i);
    }

    return 0;
}
