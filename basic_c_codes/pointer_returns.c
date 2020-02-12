#include<stdio.h>
#include<stdlib.h>

void PrintHelloWorld(){
    printf("Hello world\n");
}

int *Add(int* a, int* b){
    int* c = (int*)malloc(sizeof(int)); // heap memory address and does not get cleared immediately after function execution.
    *c = (*a) + (*b);
    return c;
    
    /*
    int c;
    c = (*a) + (*b);
    return &c;
    We can not do something like this, since function calls return from stack and memory is de-allocated and hence some garbage value will be found out
    at that address. Stack gets cleared as soon as function execution finishes/returns.
    */
}

int main(){
    int a = 2, b = 4;
    int* ptr = Add(&a, &b);
    PrintHelloWorld();
    printf("Sum = %d\n", *ptr);
}