/** Recipe to print all the alphabets of english language with their integer values *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define TOTAL_ENGLISH_ALPHABETS 26

int main() 
{
    // Don't to forget that a char is just a short int
    int initial = 'a'; 

    for (int i = 0; i < TOTAL_ENGLISH_ALPHABETS; ++i) {
        printf("%c:%d\n", initial, initial);
        ++initial;
    }
    
    return 0;
}

