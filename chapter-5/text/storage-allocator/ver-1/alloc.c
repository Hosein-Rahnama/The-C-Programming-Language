#include <stdio.h>

#include "alloc.h"

#define ALLOCSIZE 1000                  // Size of available space

static char allocbuf[ALLOCSIZE];        // Storage for allocation
static char *allocp = allocbuf;         // Next free position

char *alloc(int n)
{
    if ((allocbuf + ALLOCSIZE) - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return NULL;
}

void afree (char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

int free_space()
{
    return allocbuf + ALLOCSIZE - allocp;
}