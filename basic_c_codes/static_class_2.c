#include <stdio.h>

int *fun()
{
    static int k = 35; // value persist when use static keyword
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

/*
avoid using static
variables unless you really need them. Because their values are
kept in memory when the variables are not active, which means
they take up space in memory
*/