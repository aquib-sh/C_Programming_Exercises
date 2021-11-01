/* Exercise: Write a program to check a C program for rudimentary syntax errors 
 * like unbalanced parentheses, brackets and braces.
 * Don't forget about quotes, both single and double, escape sequences and comments.
 * (This program is hard if you do it with full generality.)
 *
 * Author: Shaikh Aquib
 *
 * ============================
 *          Explaination
 * ===========================
 * We will syntax classify errors into two types
 *
 * 1) Fundamental Errors: These are the errors for unbalanced parenthesis, braces, brackets.
 * 2) Punctuation Errors: These are the errors of unclosed single and double quotes, comments.
 *
 *     These errors will be assigned error codes for distinguishing among them
 *      ------------------------------
 *     | Code |    Description       |
 *     |------|----------------------|
 *     | -1   | unclosed single quote|
 *     | -2   | unclosed double quote|
 *     | -3   | unclosed comment     |
 *
 */

#include <stdio.h>

#define MAXLINE 2000    /* maximum number of characters in a line */
#define MAX_ERRORS 5    /* maximum number of errors to be shown to user per program */

#define UNCLOSED_SINGLE_QUOTE_ERROR -1
#define UNCLOSED_DOUBLE_QUOTE_ERROR -2
#define UNCLOSED_COMMENT_ERROR -3

#define OPENING_BRACE   '{'
#define OPENING_BRACKET '['
#define OPENING_PARENTH '('

#define CLOSING_BRACE   '}'
#define CLOSING_BRACKET ']'
#define CLOSING_PARENTH ')'

#define SQUOTE '\'' 
#define DQUOTE '\"'

#define CLOSED 1
#define OPENED 0
/* -7 will act as a signal that error records have ended in array 
 * INPUT_TERMINATION will be placed after all lines have been read from input
 * and there is no possibility to record futher errors.
 */
#define INPUT_TERMINATION -7    

char line[MAXLINE];     /* current line */
int punc_errors[MAXLINE];       /* maintains an array of lines numbers where punctuation errors occured */
int punc_error_types[MAXLINE]; /* maintains an array of error types corresponding to each line in punc_errors */

unsigned int len;           /* length of current line */
unsigned int nline;         /* number of the current line in input */
unsigned int npunc_err;     /* maintains the index of punctuation errors */
unsigned int obrace_count, obracket_count, oparenth_count;      /* opening count */
unsigned int cbrace_count, cbracket_count, cparenth_count;      /* closing count */

int getline(void);
void check_syntax(void);
void print_errors(void);

int main()
{
    /* set all counts to zero */
    obrace_count = obracket_count = oparenth_count = 0;
    cbrace_count = cbracket_count = cparenth_count = 0;
    nline = 0;
    npunc_err = 0;

    while ((len = getline()) > 0) {
        ++nline;
        check_syntax();
    }
    /* -7 will act as a signal that records have ended so no need to read further */
    punc_errors[npunc_err] = INPUT_TERMINATION;
    punc_error_types[npunc_err] = INPUT_TERMINATION;
    
    print_errors();
}

int getline(void)
{
    int i;
    char c;

    i = 0;

    while (((c = getchar()) != EOF) && c != '\n' && i < MAXLINE) {
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

void check_syntax(void)
{
    int i; 
    int c;

    unsigned char squote_status = CLOSED;    /* single quote status */
    unsigned char dquote_status = CLOSED;    /* double quote status */

    /* TODO: REMOVE THE BELOW BLOCK FOR SKIP PUNC CHECK AND IMPLEMENT COMMENTS PROPERLY */ 
    /* skip punctuation checking if char constant or comment */ 
    unsigned char skip_punc_check = 0;

    if (line[0] == '#' || line[1] == '*')
    {
        skip_punc_check = 1;
    }
    i = 0;

    while ((c = line[i]) != '\0') {
        /* increment the count based on the current character */
        switch (c) {
            case OPENING_BRACE:
                ++obrace_count;
                break;

            case OPENING_BRACKET:
                ++obracket_count;
                break;

            case OPENING_PARENTH:
                ++oparenth_count;
                break;

            case CLOSING_BRACE:
                ++cbrace_count;
                break;

            case CLOSING_BRACKET:
                ++cbracket_count;
                break;

            case CLOSING_PARENTH:
                ++cparenth_count;
                break;

            case SQUOTE:
                if (!skip_punc_check)
                    squote_status = !squote_status;
                break;

            case DQUOTE:
                if (!skip_punc_check)
                    dquote_status = !dquote_status;
                break;
       }
       ++i;
    }

    if (squote_status == OPENED)
    {
        punc_errors[npunc_err] = nline;
        punc_error_types[npunc_err] = UNCLOSED_SINGLE_QUOTE_ERROR;
        ++npunc_err; 
    }
    
    if (dquote_status == OPENED)
    {
        punc_errors[npunc_err] = nline;
        punc_error_types[npunc_err] = UNCLOSED_DOUBLE_QUOTE_ERROR;
        ++npunc_err;
    }
}

void print_errors(void)
{
    unsigned char error_free = 1;

    if (obrace_count != cbrace_count)
    {
        printf("[!] Unbalanced Braces Error\n");
        error_free = 0;
    }
    if (obracket_count != cbracket_count)
    {
        printf("[!] Unbalanced Brackets Error\n");
        error_free = 0;
    }
    if (oparenth_count != cparenth_count)
    {
        printf("[!] Unbalanced Parenthesis Error\n");
        error_free = 0;
    }
    if (error_free) 
    {
        printf("[+] No Errors Found in Program\nYour Code is Perfect!\n");
    }

    /* print punctuation errors */
    int i;
    int err_line;
    int err_type;

    for (i = 0; i <= npunc_err; ++i) {
        err_line = punc_errors[i];
        err_type = punc_error_types[i];

        if (err_line == INPUT_TERMINATION)
            break;

        if (err_type == UNCLOSED_SINGLE_QUOTE_ERROR)
        {
           printf("[!] Unclosed Single Quote Error at Line %d\n", err_line); 
        }
        else if (err_type = UNCLOSED_DOUBLE_QUOTE_ERROR)
        {
            printf("[!] Unclosed Double Quote Error at line %d\n", err_line);
        }
    }

}


