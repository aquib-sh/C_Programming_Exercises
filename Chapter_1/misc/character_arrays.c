/** 1.9 Write a program that reads a set of text lines and print the longest.
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum input line length */ 

int getline(char line[], int maxline);  /* get an input line */
void copy(char to[], char from[]);      /* copy characters from 'from char array' to 'to char array' */

int main() 
{
    int len;                /* length of current line */
    int max;                /* maximum length of a line so far */
    char line[MAXLINE];     /* current line */
    char longest[MAXLINE];  /* longest line so far */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        /** If line is longer than current longest then
         *  copy the current line to the longest. */
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {
        printf("The longest line is of %d characters\n", max);
    }

    return 0;

}

int getline(char line[], int lim)
{
    int i;
    int c;

    for (i = 0; ((i < lim) && ((c = getchar()) != EOF) && (c != '\n')); ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';     /* ended with null '\0' character (typical string ending in C) */
    
    return i;
}
    
void copy(char to[], char from[])
{
    int i;  /* array index position*/
    i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

