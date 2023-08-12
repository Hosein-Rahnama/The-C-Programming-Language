/* Copy input to output. */

#include <stdio.h>

int main()
{
    int c;

    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
    
    printf("Recieved %d.", c);
}