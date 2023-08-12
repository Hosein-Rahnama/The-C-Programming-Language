/* This program echoes its command line arguments on a single line. */

#include <stdio.h>

int main(int argc, char *argv[])
{
    while (--argc > 0)
        printf((argc > 1) ? "%s ": "%s", *++argv);
    printf("\n");

    return 0;
}