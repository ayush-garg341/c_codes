#include <stdio.h>

int main(){
    int x = 200000;
    int y = 100000;
    long long p = 200000;
    long long q = 100000;
    int a  = sizeof(int);
    printf("%d bytes\n", a);
    printf("x*y = %d\n", x*y);
    printf("p*q = %lld\n", p*q);
    return 0;
}