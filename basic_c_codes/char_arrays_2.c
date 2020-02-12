#include<stdio.h>

void print(char* c){ 

    /*
        if we use "const char* c" as function argument instead of "char* c" then we can;t modify it inside the function like;
        c[0] = A; 
    */


    // int i = 0;
    // while(*(c+i)!='\0'){
    //     printf("%c",c[i]);
    //     i++;
    // }

    while(*c!='\0'){
        printf("%c", *c);
        c++;
    }
    printf("\n");

}

int main(){
    char c[20] = "Hello"; // string gets stored in the space for an array in stack.
    char *d = "Hello"; // string gets stored as compile time constant in text section of memory ( RAM ).
    print(c);
    return 0;
}