/*** Recipe to get the input from keyboard until EOF using a smarter way
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

int main() 
{
    char c;

    while((c = getchar()) != EOF) {
        printf("%c\n", c);
    }

    return 0;
}
