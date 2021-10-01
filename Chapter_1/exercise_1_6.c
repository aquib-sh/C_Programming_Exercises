/** Exercise: Verify that the expression getchar() != EOF is 0 or 1
 *
 * Author: Shaikh Aquib
 * 
 * Program must give 1 when it not Ctrl + D (Ctrl + Z on Windows)
 * and 0 when Ctrl + D is entered.
 */

#include <stdio.h>

int main()
{
    printf("value is:%d\n", (getchar() != EOF));
}

