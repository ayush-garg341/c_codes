#include<stdio.h>

int main()
{
    int a = -1;
    unsigned int b = 1;
    printf("%u\n", a + b);
}


// When we mix signed and unsigned types in an expression, the signed value is usually converted to unsigned.
