#include<stdio.h>

int main(){
    int x = 5;
    int* p = &x;
    *p = 6;
    int** q = &p;
    int*** r = &q;
    printf("Address of x = %d\n", &x);
    printf("Value of p = %d\n", p);
    printf("Value at address p = %d\n", *p);
    printf("Address of p = %d\n", &p);
    printf("value of q = %d\n", q);
    printf("Value at address q = %d\n", *q);
    printf("%d\n", **q);
    printf("Address of q = %d\n", &q);
    printf("value of r = %d\n", r);
    printf("%d\n", **r);
    printf("%d\n", ***r);
    ***r = 10;
    printf("x = %d\n", x);
    **q = *p + 2;
    printf("x = %d\n", x);
}
