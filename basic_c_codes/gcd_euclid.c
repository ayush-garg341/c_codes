#include <stdio.h>

/*
In 1840s it was found that time complexity of euclid's algorithm depends upon the number of digits the smaller number has.
to calculate number of digits log(number) to the base 10. 
Can be converted to log(number) to the base 2 while ignoring constant. 
Hence time complexity is log(number) to the base 2.
*/

int main()
{
    int a, b, remainder;
    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter another number\n");
    scanf("%d", &b);

    int orig_a = a;
    int orig_b = b;

    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    printf("GCD of two numbers (%d, %d) is %d\n", orig_a, orig_b, a);

    return 0;
}