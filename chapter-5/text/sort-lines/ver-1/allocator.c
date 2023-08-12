#include <stdio.h>

#include "sort.h"

#define ALLOCSIZE (MAXLINES * MAXLEN)       // Memory allocated for the input text

static char allocbuf[ALLOCSIZE];            // Storage for allocation
static char *allocp = allocbuf;             // Next free position

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