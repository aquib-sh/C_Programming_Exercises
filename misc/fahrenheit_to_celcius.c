/** Recipe to convert Fahrenheit to Celcius temperature
    Formula: C = (F-32) * (5/9)

    Author: Shaikh Aquib
**/

#include <stdio.h>

int main()
{
    float celcius, fahr;
    int lower, upper, step;

    lower = 0;    /* Lower limit of temperature table */
    upper = 300;  /* Upper limit of temperature table */
    step = 20;   
    fahr = lower;

    while(fahr <= upper) {
        celcius = ((fahr-32.0) * (5.0/9.0));
        printf("%3.0f\t%6.2f\n", fahr, celcius);
        fahr += step;
    }

    return 0;
}


