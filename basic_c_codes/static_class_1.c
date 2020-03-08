#include <stdio.h>

int *fun()
{
    int k = 35;
    return (&k);
}

int main()
{
    int *j;
    j = fun();
    printf("ayush\n");
    printf("%d\n", *j);
    return 0;
}
