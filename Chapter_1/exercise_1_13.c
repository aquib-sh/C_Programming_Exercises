/** Exercise: Write a program to print a histogram of the lengths of words in it's input.
 *            It is easy to draw the histogram with bars horizontal; a vertical orientation
 *            is more challenging.
 *
 *  Author : Shaikh Aquib
 */

#include <stdio.h>

#define MAX_WORD_LENGTH 20

int main()
{
    int c, count;
    int nwords[MAX_WORD_LENGTH]; 

    /**nwords[1] will represent count of words that have length 1.
     * nwords[2] will represent count of words that have length 2.
     * nwords[n-1] will represnet count of words that have length n-1.
     * nwords[n] will represnet count of words that have length n.
     */

    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        nwords[i] = 0;
    }

    count = 0; //word length

    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\t' || c == '\n') && (count > 0))
        {
            /** clearly we know a word with 0 length is not a word
             * so why waste energy incrementing it...
             * only increment when greater then 0
             */
            ++nwords[count];
            count = 0;
        }
        else
        {
            ++count;
        }
    }

    int word_count; 

    printf("========================\n");
    printf("||HORIZONTAL HISTOGRAM||\n");
    printf("========================\n");
    for (int i = 1; i < MAX_WORD_LENGTH; ++i) {
        word_count = nwords[i];

        printf("\n");
        printf("%d\t", i);

        for (int j = 0; j < word_count; ++j) {
            printf("$");
        }
        printf("\n");
    }

    printf("======================\n");
    printf("||VERTICAL HISTOGRAM||\n");
    printf("======================\n");
    // Find the maximum occurence of a word of any length (i.e find the max value in nwords)
    int max_repeated_word = 0;
    for (int i = 1; i < MAX_WORD_LENGTH; ++i) {
        word_count = nwords[i];
        if (word_count > max_repeated_word)
            max_repeated_word = word_count;
    } 

    // Now after having the max value we are good to print our vertical histogram
    // if word_count at a particular index is not equal to max_repeated_count then print ' ' 
    // if equal then print $$ 
    for (int i = max_repeated_word; i >= 0; --i) {
        for (int j = 1; j < MAX_WORD_LENGTH; ++j) {
            // if it's the last time then print numbers only
            if (i == 0) 
            {
                printf("%-3d", j);
            }
            else
            {
                if (nwords[j] >= i)
                {
                    printf("$$ ");
                }
                else
                {
                    printf("   ");
                }
            }
        }
        printf("\n");
    }

    return 0;    
}
 
