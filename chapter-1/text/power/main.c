/* A rudimentary power function, which raises an integer
   to the power of a positive integers. */

#include <stdio.h>

int power(int base, int n);

int main()
{
    int i;

    for (i = 0; i < 10; i++)
        printf("%1d %4d %7d\n", i, power(2, i), power(-3, i));

    return 0;
}

int power(int base, int n)
{
    int i, p;

    p = 1;
    for (i = 1; i <= n; i++)
        p = p * base;

    return p;
}