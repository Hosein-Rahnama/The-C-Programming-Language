/* This program converts an uppercase character to a 
   lowercase character. */

#include <stdio.h>

char my_tolower(char c);

int main()
{
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    printf("Lower case of %c is %c.", c, my_tolower(c));

    return 0;
}

char my_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}