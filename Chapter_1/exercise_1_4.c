/** Exercise: Write a program to print the corresponding Celcius to Fahrenheit table.
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

int main()
{
    printf("Celcius\tFahrenheits\n");
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celcius = lower;

    while (celcius <= upper) {
        fahr = (celcius * (9.0/5.0)) + 32;
        printf("%6.2f\t%3.2f\n", celcius, fahr);
        celcius += step;
    }

    return 0;
}

     


