#include <stdio.h>

int increment()
{
    static int i = 1;
    printf("%d\n", i);
    i = i + 1;

    return 0;
}

int main()
{
    increment();
    increment();
    increment();
}
