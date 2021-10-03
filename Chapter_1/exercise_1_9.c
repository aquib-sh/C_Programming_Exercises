/** Exercise: Write a program to copy it's input to it's output, 
 *            replacing each string of one or more blanks by a single blank
 *
 *Author: Shaikh Aquib
 */

#include <stdio.h>

#define NEW_SPACE 0 //new space character in a line

int main()
{
    int c;
    int space_count = 0; //counts how many consecutive space occour

    while ((c = getchar()) != EOF) {
        if (c == ' ')
        {
            if (space_count == NEW_SPACE)
            {
                putchar(c);
            }
            ++space_count;
        }
        else
        {
            putchar(c);
            //Reset the space count after every new word is encountered
            space_count = 0;
        }
    }

    return 0;
}

        
