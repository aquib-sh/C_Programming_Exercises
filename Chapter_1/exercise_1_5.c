/** Exercise: Modify the temperature program to print the table in reverse order,
 *            that is from 300 degrees to 0.
 *  
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

int main() 
{
    printf("Fahrenheits\tCelcius\n");

    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;

    while (fahr >= lower) {
        celcius = (fahr-32) * (5.0/9.0);
        printf("%3.0f\t\t%6.2f\n", fahr, celcius);
        fahr -= step;
    }

    return 0;
}

