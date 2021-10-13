/** Exercise: Write a program detab that replaces tabs in the inputs 
 *  with the proper number of blanks to space to the next tab stop.
 *  Assume a fixed set of tab stops, say every n columns.
 *  should n be a variable or a symbolic parameter?
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define MAXLINE 2000        /* maximum number of chars in an input line. */
#define TABSIZE_IN_SPACES 4 /* we will assume tab = 4 spaces. */

int len;                    /* length of the current line. */
char line[MAXLINE];         /* current line */
char refined_line[MAXLINE]; /* line having tabs replaced with spaces. */

int getline(void);
void replace_tabs_with_spaces(void);
void print_array(void);

int main()
{
    while ((len = getline()) > 0) {
        replace_tabs_with_spaces();
        print_array();
    }

    return 0;
}

int getline(void) 
{
    int i;  /* records the length of the current line */
    char c;

    i = 0;
    while ((((c = getchar()) != EOF) && (c != '\n')) && (i < MAXLINE)) {
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

void replace_tabs_with_spaces(void)
{
    int i;  /* index for line */
    int j;  /* index for refined line */
    int k;  /* will be used for adding spaces */
    char c; /* individual character in line */

    i = j = 0;

    while ((c = line[i]) != '\0') {
        if (c == '\t')
        {
            for (k = 0; k < TABSIZE_IN_SPACES; ++k) {
                refined_line[j] = ' ';
                ++j;
            }
        }
        else
        {
            refined_line[j] = line[i];
            ++j;
        }
        ++i;
    }

} 

void print_array(void)
{
    int i;

    for (i = 0; i < len; ++i) {
        putchar(refined_line[i]);
    }
}
