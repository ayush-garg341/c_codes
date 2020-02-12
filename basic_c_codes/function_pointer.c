// Function pointers in C/C++
#include<stdio.h>

int Add(int a, int b){
    return a+b;
}

void PrintHello(char *name){
    printf("Hello %s\n", name);
}

// int *Func(int, int); declaring a function that would return int* i.e. pointer to integer.
// int (*Func)(int, int); declaring a function pointer.

int main(){
    int c;
    int (*p)(int, int); // function to pointer that should take (int, int) as argument/parameter and return int.
    p = &Add; // or just Add
    c = (*p)(2,3); // de-referencing and executing the function.
    printf("%d\n", c);

    void (*ptr)(char*);
    ptr = PrintHello;
    ptr("Ayush");

}