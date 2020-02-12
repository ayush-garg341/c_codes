#include<stdio.h>

void A(){
    printf("hello\n");
}

void B(void (*ptr)()){ // function pointer as argument.
    ptr(); // call-back function that "ptr" points to.
}

int main(){
    void (*ptr)() = A;
    B(ptr);
    // B(A) this will also work.
    return 0;
}