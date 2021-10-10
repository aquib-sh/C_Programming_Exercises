/** Exercise: Write a program to remove trailing blanks and tabs from each line of input,
 *  and to delete entirely blank lines.
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define MAXLINE 2000    /* maximum length of input line */

int getline(char line[], int lim);               /* reads a line into char array and outputs it's length */
int remove_whitespaces(char to[], char from[]); /* removes trailing blanks, tabs and entire blank lines. */
void print_array(char a[]);                       /* print the array */

int main()
{
    int len;                    /* length of current line */
    char line[MAXLINE];         /* current line */ 
    char refined_line[MAXLINE]; /* refined line returned after removing whitespaces */

    while ((len = getline(line, MAXLINE)) > 0) {
        len = remove_whitespaces(refined_line, line);
        if (len > 1)
            print_array(refined_line);
    }
}

int getline(char line[], int lim)
{
    int i;
    int c;
    i = 0;

    while ((c = getchar()) != EOF && (c != '\n') && (i < lim)) {
        line[i] = c;
        ++i;
    }
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

int remove_whitespaces(char to[], char from[])
{
    int i, j;
    char c, prev;

    i = 0;  /* index for 'from' array */
    j = 0;  /* index for 'to' array */
    
    /* first char is new line means line is empty */
    if (from[0] == '\n')
        return 1;

    prev = ' '; /* prev will maintain the record previous element */

    while ((c = from[i]) != '\0') {
        /* character must not be tabs or trailing blanks (spaces) */
        if (c != '\t' && !(c == prev && prev == ' '))
        {
            to[j] = from[i];
            ++j;                /* increment j only if it meets the condition. */
        }
        ++i;
        prev = c;   /* assign the current char to prev */
    }
    to[j] = '\0';

    return j;
}

void print_array(char a[])
{
    int i;
    char c;
    
    i = 0;
    
    while ((c = a[i]) != '\0') {
        putchar(c);
        ++i;
    }
}
           

