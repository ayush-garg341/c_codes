#include<stdio.h>

float float_sum(float a[], unsigned len)
{
    int i;
    float result = 0;
    for(i = 0; i <= len - 1; i++)
    {
        result += a[i];
    }
    return result;
}

int main()
{
    float a[5] = {1.2, 1.4, 1.5, 1.6, 1.1};
    unsigned len = 5;
    float res;
    res = float_sum(a, len);
    printf("%.2f\n", res);
}


// This program demonstrate how easily bugs can arise due to implicit casting from signed to unsigned.
// Since parameter len is unsigned, the computation 0 - 1 is performed using unsigned arithmetic. The result is Umax ( unsigned max value ).
// The <= comparison is also performed using an unsigned comparison and since any number is less than or equal to Umax, the comparison holds.
// The code attempts to access invalid elements of array a.


// Fixes:
// change type of len from unsigned to int or,
// Change the test of for loop to be i < length.
