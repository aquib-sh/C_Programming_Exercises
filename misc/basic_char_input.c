/** Recipe for basic input output using getchar() and putchar()
 *  The program will continue to take input and print it on the console until
 *  it find and EOF character, 
 *  For UNIX EOF is Ctrl + D and For Windows it is Ctrl + Z
 *
 *  Author: Shaikh Aquib
 */


#include <stdio.h>

int main()
{
    //Take character input
    //getchar() takes an input char
    int a;
    a = getchar();

    //Now multiply the char by 5 and output the results
    //putchar() outputs a char
    //loop until end of the file is not reached
    while (a != EOF) {
        putchar(a);
        a = getchar();
    }

    return 0;
}
