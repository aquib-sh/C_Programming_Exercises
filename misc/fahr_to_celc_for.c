/** Recipe to convert Fahrenheit temperature to celcius
 *  Using For loop
 *
 *  Author: Shaikh Aquib
**/

#include <stdio.h>

int main() 
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    for(fahr = lower; fahr <= upper; fahr += 20) {
        celcius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.2f\n", fahr, celcius);
    }

    return 0;
}

   
