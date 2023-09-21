/* This program is a memory allocator trying to simulate malloc and free
   functions of the standard library. */

#include <stdio.h>
#include <string.h>

#include "alloc.h"

int main()
{
    int n = 16;
    int *p = (int *)(mem_alloc(n * sizeof(int)));
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < n; i++)
        printf("%d%s", i, (i < n - 1) ? ", ": ".\n");

    int m = 32;
    char *q = (char *)(mem_alloc(m * sizeof(char)));
    strcpy(q, "Allocating Memory ...\n");
    printf("%s", q);

    printf("Header size is %ld.\n", sizeof(Header));

    // The order of freeing is arbitrary and is not affected by the order of allocating.
    printf("Available space is %d bytes.\n", free_space());
    mem_free(p);
    printf("Available space is %d bytes.\n", free_space());
    mem_free(q);
    printf("Available space is %d bytes.\n", free_space());

    return 0;
}