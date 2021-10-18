/** Recipe to convert Fahrenheit temperature to celcius temperature 
 *  using for loop and symbolic constants definition
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

int main()
{
    float fahr, celcius;

    for(fahr=LOWER; fahr <= UPPER; fahr += 20) {
        celcius = (fahr - 32) * (5.0/9.0);
        printf("%3.0f\t%6.2f\n", fahr, celcius);
    }

    return 0;

}

