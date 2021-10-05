/** Exercise: Write a program to print a histogram of the frequencies of different characters in it's input.
 *  
 *  Author: Shaikh Aquib
 */

#include <stdio.h>

#define TOTAL_ENGLISH_ALPHABETS 26

int main() 
{
    char c;
    char initial = 'a';
    char characters[TOTAL_ENGLISH_ALPHABETS]; //characters in English language
    int frequency[TOTAL_ENGLISH_ALPHABETS];   //frequency corresponding to each character

    // Add all the values of English characters to array
    for (int i = 0; i < TOTAL_ENGLISH_ALPHABETS; ++i) {
        characters[i] = initial;
        frequency[i] = 0;
        ++initial;
    }

    while ((c = getchar()) != EOF) {
        for (int i = 0; i < TOTAL_ENGLISH_ALPHABETS; ++i) {
            if (c == characters[i]) 
            {
                ++frequency[i];
            }
        }
    }

    /** Create a vertical histogram for character and frequency **/
   // first get the max of all the frequencies 
   int cfrequency, max_frequency;
   cfrequency = max_frequency = 0;

   for (int i = 0; i < TOTAL_ENGLISH_ALPHABETS; ++i) {
       cfrequency = frequency[i];
       if (cfrequency > max_frequency)
           max_frequency = cfrequency;
   }

   for (int i = max_frequency; i >= 0; --i) {
       for (int j = 0; j < TOTAL_ENGLISH_ALPHABETS; ++j) {
           if (i == 0)
           {
               printf("%-3c", characters[j]);
           }
           else
           {
               if (frequency[j] >= i)
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

   


