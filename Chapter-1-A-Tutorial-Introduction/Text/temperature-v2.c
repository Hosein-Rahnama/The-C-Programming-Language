/* Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300. */

#include <stdio.h>

#define LOWER 0          // Lower limit of temperature table.
#define UPPER 300        // Upper limit of temperature table.
#define STEP 20          // Step size.

int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    
    return 0;
}