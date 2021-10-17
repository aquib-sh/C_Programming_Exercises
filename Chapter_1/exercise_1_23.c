/* Exercise: Write a program to remove all comments from a C program. 
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 *
 * Author: Shaikh Aquib
 */

#include <stdio.h>

#define MAXLINE 3000

int len;
char line [MAXLINE];

int getline(void);
int remove_comments(int toggle_value);

int main()
{
    /* toggle turns on or off depending upon whether interating over a comment or not */
    int toggle = 0; 

    while ((len = getline()) > 0) {
        toggle = remove_comments(toggle);
    }
}

int getline(void)
{
    int i;
    char c;

    i = 0;

    while (((c = getchar()) != EOF) && c != '\n') {
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

int remove_comments(int toggle_value)
{
    int i;                  /* character index of line */
    int del_toggle;         /* toggle turns on or off depending upon whether comment encountered */
    int toggle_off_point;   /* records the index at which toggle was commanded be off,
                             * if index == toggle_off_point + 2 then finally turn off toggle. */

    del_toggle = toggle_value;
    toggle_off_point = -3;
    i = 0;

    while (line[i] != '\0') {
        /* if next index is not out of range
         * if element at current index is '/'
         * AND
         * if element at next index is '*' then toggle on
         * ELSE
         * if vice versa then turn off the toggle after (index + 2) position is reached
         * output the character if and only if del_toggle is off.
         */
        if (((i+1) < MAXLINE) && line[i] == '/' && line[i+1] == '*') 
            del_toggle = 1;

        else if (((i+1) < MAXLINE) && line[i] == '*' && line[i+1] == '/') 
            toggle_off_point = i;

        else if (i == (toggle_off_point+2))
            del_toggle = 0;
        
        if (!del_toggle) 
            putchar(line[i]);

        ++i;
    }
    /* return the toggle value to be used next time. */
    return del_toggle;
}


