/** Exercise: Revise the main routine of the longest-line program so it will correctly
 *  print the length of arbitrarily long input lines as much as possible of the text.
 *  
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

int getline();

int main()
{
    int curr; /* current line length. */
    int max;  /* maximum length of a line found so far. */
    max = 0;

    while ((curr = getline()) != 0) {
        if (curr > max)
            max = curr;
    }

    printf("The longest line in file is of %d\n", max);

}

int getline()
{
    int i;
    int c;
    i = 0;
    while (((c = getchar()) != EOF) && (c != '\n'))
        ++i;
    return i;
}

        
