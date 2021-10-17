/** Exercise: Write a program to "fold" long input lines into two or more shorter lines 
 *  after the last non-blank character that occurs before the n-th column of input. 
 *  Make sure your program does something intelligent with very long lines, 
 *  and if there are no blanks or tabs before the specified column.
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define MAXLINE 2000        /* maximum number of characters in a line */
#define LINE_MAX_WIDTH 50    /* justify line at this specific character number is reached */

int len;
char line[MAXLINE];

int getline(void);
void printline(void);

int main()
{
    while ((len = getline()) > 0) {
        printline();
    }
}

int getline(void)
{
    int i;
    char c;

    i = 0;

    while (((c = getchar()) != EOF) && (c != '\n') && (i <= MAXLINE)) {
        line[i] = c;
        ++i;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

void printline(void)
{
    int i;  /* line index */
    int w;  /* line width */
    char c;

    int width_exceeded = 0;

    i = 0;
    w = 0;

    while ((c = line[i]) != '\0') {
        /* if width crosses the max line width then we will set the indicator to true
         * and wait until word ends */
        if (w > LINE_MAX_WIDTH)
            width_exceeded = 1;

        /* if width is exceeded and current character doesn't belong to a word
         * then put line break */
        if (width_exceeded && (c == ' ' || c == '\t')) 
        {
            putchar('\n');
            width_exceeded = 0; /* set width exceed indicator to false */
            w = 0;              /* reset line width count */
        }
        else
        {
            putchar(c);
            ++w;    /* increment line width count */
        }
        ++i;    /* increment index */
    }
}
