/*** Correct Approach for character counting by ignoring \n character
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

int main()
{
    long count;
    int c;
    count = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\n') { 
            ++count; 
        }
    }
    printf("%ld is the count of input characters\n", count);
} 
