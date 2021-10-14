/** Exercise: Write a program entab that replaces strings of blanks by the minimum
 *  number of tabs and blanks to achieve the same spacing. Use same tab stops as for detab.
 *  When either a tab or a single blank would suffice to reach a tab stop,
 *  which should be given preference?
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define TABSTOP 8       /* 1 tab = 4 spaces */
#define MAXLINE 2000    /* maximum number of characters in a line */

int len;
char line[MAXLINE];
char refined_line[MAXLINE];

int getline(void);
void replace_blanks_with_tabs(void);
void print_array(void);

int main()
{
    while ((len = getline()) > 0) {
        replace_blanks_with_tabs();
        print_array();
    }
}
     
int getline(void)
{
    int i;  /* number of characters in line */
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

void replace_blanks_with_tabs(void)
{
    int i;              /* index of line */
    int j;              /* index of refined line */
    char c;             /* char from line */
    int total_blanks;    /* maintains a count for total blanks */

    i = j = 0;
    total_blanks = 0;

    while ((c = line[i]) != '\0') {
        if (c == ' ')
        {
            ++total_blanks;
        }
        else 
        {
            /* add tabs and spaces until no blanks are left */
            while (total_blanks > 0) {
                if (total_blanks >= TABSTOP) 
                {
                    refined_line[j] = '\t';
                    total_blanks -= TABSTOP;
                }
                else
                {
                    refined_line[j] = ' ';
                    --total_blanks; 
                }
                ++j;
            }
            refined_line[j] = c;
            ++j;
        }
        ++i;
    }
}

void print_array(void)
{
    int i;
    char c;

    i = 0;

    while ((c = refined_line[i]) != '\0') {
        putchar(c);
        ++i;
    }
}
