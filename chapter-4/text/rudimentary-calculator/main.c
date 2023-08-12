/* This is a rudimentary calculator which reads one number per line and adds
   them up, printing the running sum after each input. */

#include <stdio.h>

#define MAXLINE 100

/* Change the return type to int. Do you get a mismatch error for the inconsistency
   between this declaration and the definition of atof? We will solve this issue
   by using header files in the reverse-polish-calculator program. */
double atof(char s[]);
int atoi(char s[]);
int getline(char line[], int lim);

int main()
{
    double sum;
    int rounded_sum;
    char line[MAXLINE];

    sum = rounded_sum = 0;
    while (getline(line, MAXLINE) > 0)
    {
        printf("\tsum: %g\n", sum += atof(line));
        printf("\trounded sum: %d\n", rounded_sum += atoi(line));
    }
        
    return 0;
}