/* This program shows the longest line of an input. */

#include <stdio.h>
#define MAXLINE 1000        // Maximum input line size

int getline(char line[], int max);
void copy(char to[], char from[]);

int main()
{
    int len;                      // Current line length
    int max;                      // Maximum line length seen so far
    char line[MAXLINE];           // Current input line
    char longest[MAXLINE];        // Longest line saved so far

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
    {
        printf("The longest line has %d characters and is given below.\n", max);
        printf("%s", longest);
    }
    
    return 0;
}

// Read a line and return its length.
int getline(char line[], int max)
{
    int c, i;
    for (i = 0; i < max -1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

// Copy 'from' into 'to' assuming that 'to' is big enough.
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}