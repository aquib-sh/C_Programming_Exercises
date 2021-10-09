/** Exercise: Rewrite the temperature conversation program of Section 1.2 to use a function for conversation.
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

float fahr_to_celcius(int);

int main() 
{
    int upper, lower, step;
    upper = 300;
    lower = 0;
    step = 20;

    int fahr;
    float celcius;
    fahr = celcius = 0;

    while(fahr <= upper) {
        celcius = fahr_to_celcius(fahr);
        printf("%d\t%.2f\n", fahr, celcius);
        fahr += step;        
    }

}

float fahr_to_celcius(int fahr) {
    float celcius = (fahr - 32) * (5.0/9.0);
    return celcius;
}
    
