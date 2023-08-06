/* This is a calculator that takes inputs in reverse polish notation. */

#include <stdio.h>
#include <stdlib.h>         // For atof

#define MAXOP 100           // Maximum size of operand or operator
#define NUMBER '0'          // Signal that a number was found

int getop(char s[]);
void push(double f);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];          // Character array containing an operand or operator

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("\t%.8g\n", pop());
                    break;
            case '\n':
                printf("\tans = %f\n", pop());
                printf("Enter a new expression or finish the program.\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    
    return 0;
}

#define MAXVAL 100          // Maximum depth of val stack

int sp = 0;                 // Next free stack position
double val[MAXVAL];         // Value stack

// Push f onto value stack
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

// Pop and return top value from tack.
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int c);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    // If c is an operator return it.
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    // Collect integer part.
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    // Collect fraction part.
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];          // Buffer for ungetch
int bufp = 0;               // Next free position in buf

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