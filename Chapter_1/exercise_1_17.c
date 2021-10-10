/** Exercise: Write a program to print all the input lines that are longer than 80 characters.
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define MAXLINE 8000

int getline(char line[], int lim);
void printline(char line[]);

int main() 
{
    int len;    /* current line length*/
    char line[MAXLINE]; /* current line */

    while ((len = getline(line, MAXLINE)) != 0) {
        if (len > 80)
            printline(line);
    }

    return 0;

}

int getline(char line[], int lim)
{
    int i;
    int c;
    i = 0;

    while (((c = getchar()) != EOF) && (c != '\n') && (i < lim)) {
        line[i] = c;
        ++i;
    }
    if (c == '\n')
        ++i;

    line[i] = '\0';

    return i;
}

void printline(char line[])
{
    int i;
    int c;
    i = 0;

    while ((c = line[i]) != '\0') {
        putchar(c);
        ++i;
    }
}
