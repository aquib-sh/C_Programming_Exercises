/** Exercise: Write a program that prints it's input one word per line
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            putchar('\n');
        }
        else 
        {
           putchar(c);
        }
    }

    return 0;
}

