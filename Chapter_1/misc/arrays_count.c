/** Recipe to count the number of occurrences of each digit of whitespace, characters
 * (blank, tab, newline) 
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

#define DIGIT_RANGE 10  //There are 10 digits in a decimal number system.

int main()
{
    int c, nwhite, nother;
    int ndigit[DIGIT_RANGE];

    nwhite = nother = 0;

    //Add 0 to all the postions before getting inputs
    for (int i = 0; i < DIGIT_RANGE; ++i) {
        ndigit[i] = 0;
    }

    //We will increment the values on position to represent
    //the count has increased.
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            ++nwhite;
        }
        else if (c >= '0' && c <= '9') {
            ++ndigit[c-'0'];
        }
        else
        {
            ++nother;
        }
    }

    //Now print the results
    printf("White Spaces: %d\n", nwhite);
    printf("Other Characters: %d\n", nother);
   
    printf("Numberical characters:\n"); 
    for (int i = 0; i < DIGIT_RANGE; ++i) {
        printf("Digit: %d\tCount: %d\n", i, ndigit[i]);
    }

    return 0;
}





