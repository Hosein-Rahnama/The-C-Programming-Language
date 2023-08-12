/* This program converts declaration to word description. */

#include <stdio.h>
#include <string.h>

#include "dcl.h"

// Define external variables.
int tokentype;                  // Type of last token
char token[MAXTOKEN];           // Last token string
char name[MAXTOKEN];            // Identifier name
char datatype[MAXTOKEN];        // Data types like char, int, etc.
char out[1000];                 // Output string

int main()
{
    while (gettoken() != EOF)
    {
        // First token on a given line is the datatype.
        strcpy(datatype, token);
        out[0] = '\0';
        // Parse rest of the line.
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }

    return 0;
}