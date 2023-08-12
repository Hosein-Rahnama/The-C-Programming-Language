/* This program manages an allocated memory. */

#include <stdio.h>
#include <string.h>

#include "allocator.h"

void print_string(char *s);

int main()
{
    int i, n;
    char *s;

    s = "I am learning C.";
    n = strlen(s);
    char *p = alloc(n + 1);
    if (p == NULL)
        printf("Not enough space for storing p.\n");
    else
    {
        for (i = 0; i < n; i++)
            p[i] = s[i];
        p[i] = '\0';
        print_string(p);
        printf("\n");
    }

    s = "Awesome!";
    n= strlen(s);
    char *q = alloc(n + 1);
    if (q == NULL)
        printf("Not enough space for storing q.\n");
    else
    {
        for (i = 0; i < n; i++)
            q[i] = s[i];
        q[i] = '\0';
        print_string(q);
        printf("\n");
    }

    printf("Available space is %d Bytes.\n", free_space());
    afree(q);
    printf("Available space is %d Bytes.\n", free_space());
    afree(p);
    printf("Available space is %d Bytes.", free_space());

    return 0;
}

void print_string(char *s)
{
    while (*s != '\0')
        printf("%c", *(s++));
}