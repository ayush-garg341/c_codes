#include <stdio.h>

int euclid_gcd_recursive(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return euclid_gcd_recursive(b, a % b);
    }
}

int main()
{
    int a, b, gcd;
    printf("Enter first number\n");
    scanf("%d", &a);

    printf("Enter another number\n");
    scanf("%d", &b);

    gcd = euclid_gcd_recursive(a, b);

    printf("GCD of two numbers (%d, %d) is %d\n", a, b, gcd);

    return 0;
}