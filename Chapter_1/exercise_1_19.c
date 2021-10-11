/** Exercise: Write a function reverse(s) that reverses the character string s.
 *  Use it to write a program that reverses it's input a line at a time.
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define MAXLINE 1000    /* maximum characters in a line. */

int getline(char line[], int maxline);                                 /* takes an input line */
void reverse(char simple_line[], char reversed_line[], int length);   /* reverses a string */
void print_array(char a[]);                                            /* prints an array of characters */

int main()
{
    int len;                /* total characters in current line. */
    char line[MAXLINE];     /* current line */
    char reversed_line[MAXLINE]; /* current line reversed */ 

    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(reversed_line, line, len);
        print_array(reversed_line);
    }

    return 0;
} 

int getline(char line[], int lim)
{
    int i;
    char c;

    for (i = 0; (i < lim && ((c = getchar()) != EOF) && c != '\n'); ++i)
       line[i] = c;

    if (c == '\n') {
        line[i] = '\n';
        ++i;
    }

    line[i] = '\0';
    return i;
}

void reverse(char rev[], char line[], int len)
{
    int i, j;
    j = 0;
    
    for (i = len-2; i >= 0; --i) {
        rev[j] = line[i];
        j++;
    }

    rev[j] = '\n';
    rev[j+1] = '\0';
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



