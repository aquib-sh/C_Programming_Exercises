/** Exercise: Write a program to determine the ranges of char, short, int and long
 *  both signed and unsigned, by printing appropirate values from standard headers and
 *  by direct computation. Harder if you compute them: determine the ranges of various
 *  floating point types:
 *
 *  Author: Shaikh Aquib
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() 
{
    printf("signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char: 0 to %d\n\n", UCHAR_MAX);

    printf("signed short: %hi to %hi\n", SHRT_MIN, SHRT_MAX); 
    printf("unsigned short: 0 to %hu\n\n", USHRT_MAX);

    printf("signed int: %d to %d\n", INT_MIN, INT_MAX); 
    printf("unsigned int: 0 to %i\n\n", UINT_MAX); 

    printf("signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n\n", ULONG_MAX);
}


