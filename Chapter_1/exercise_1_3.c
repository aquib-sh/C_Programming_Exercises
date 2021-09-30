/** Exercise 1-3: Modify the temperature conversion program to print a heading above the table.
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

int main()
{
    printf("Fahrenheits\tCelcius\n");

    float fahr, celcius;
    int lower, upper, step;

    lower = 0;     // Lower value of table
    upper = 300;   // Upper value of table
    step = 20;     // increment table values by 20 

    while(fahr <= upper) {
        celcius = (5.0/9.0) * (fahr-32);
        printf("%3.0f\t\t%6.2f\n", fahr, celcius);
        fahr += step;
    }

    return 0;
}




