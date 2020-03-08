#include <stdio.h>

int i; // external storage class default value = 0 and persist through out the program
int main()
{
    printf("\ni = %d", i);
    increment();
    increment();
    decrement();
    decrement();
    return 0;
}
int increment()
{
    i = i + 1;
    printf("\non incrementing i = %d\n", i);
    return 0;
}
int decrement()
{
    i = i - 1;
    printf("\non decrementing i = %d\n", i);
    return 0;
}