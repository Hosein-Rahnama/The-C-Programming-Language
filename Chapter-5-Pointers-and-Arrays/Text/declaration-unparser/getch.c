#include <stdio.h>

#include "undcl.h"

#define BUFSIZE 100

static char buf[BUFSIZE];          // Buffer for ungetch
static int bufp = 0;               // Next free position in buf

// Get a (possibly pushed back) character.
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push character back on input.
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters");
    else
        buf[bufp++] = c;
}