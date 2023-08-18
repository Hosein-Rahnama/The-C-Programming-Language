/* This program converts an uppercase character to a 
   lowercase character. */

#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;

    while ((c = getchar()) != EOF)
        putchar(tolower(c));

    return 0;
}