/* Count the number of digits in input. */

#include <stdio.h>

int main()
{
    int c, i, nwhite = 0, nother = 0;
    int ndigit[10];

    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ndigit[c - '0']++;
        else if (c == ' ' || c == '\n' || c == '\t')
            nwhite++;
        else
            nother++;

    for (i = 0; i < 10; i++)
    {
        printf("Occurrences of %d: ", i);
        printf(" %d\n", ndigit[i]);
    }    
    printf("White Space: %d\n", nwhite);
    printf("Other: %d\n", nother);

    return 0;
}