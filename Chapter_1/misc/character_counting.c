/*** Recipe for Character Counting
 *
 * Author: Shaikh Aquib
 *
 * Note: This will print the count twice to the characters you inputed
 *       Because when you enter a character from input and press enter the \n stays in buffer
 *       and is read before any next iteration, hence it gives double input.
 *       Refer to the next misc if you want to know how to handle this.
 */

#include <stdio.h>

int main() 
{
    long count;

    count = 0;

    while (getchar() != EOF) {
        ++count;
    }

    printf("There were %ld characters in input\n", count);

}

