/** Exercise: Write a program to count blanks, tabs and newlines
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

int main()
{
    int c;
    int blanks, tabs, newlines;
    blanks = tabs = newlines = 0;

    while ((c = getchar()) !=  EOF) {
        switch(c) {
            case ' ': 
                ++blanks;
                break;
           
            case '\t':
                ++tabs;
                break;

            case '\n':
                ++newlines;
                break;
        }
    }

    printf("Blanks count: %d\n", blanks);
    printf("Tabs count: %d\n", tabs);
    printf("Lines count: %d\n", newlines);

    return 0;
}

