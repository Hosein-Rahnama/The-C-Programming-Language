/* This program converts a number stored as a character array
   to an integer. The function name 'atoi' is an abbreviation  
   for ASCII to integer. This is a more general version of the
   program given in Chapter 2. This omits the white spaces and
   handles the sign. */

#include <stdio.h>
#include <ctype.h>

int my_atoi(char s[]);

int main()
{
    char s[] = "-12987Text524Junk";

    printf("%d", my_atoi(s));

    return 0;
}

int my_atoi(char s[])
{
    int i, n, sign;

    for(i = 0; isspace(s[i]); i++);
    sign = (s[i] == '-' ? -1 : 1);
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    
    return sign *n;
}