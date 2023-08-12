/* Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300. */

#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;          // Lower limit of temperature table.
    upper =300;         // Upper limit of temperature table.
    step = 20;          // Step size.
    printf("Fahrenheit to Celsius Conversion Table\n");
    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f\t%5.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}