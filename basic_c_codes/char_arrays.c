#include<stdio.h>
#include<string.h>

int main(){
    char c[20];
    c[0] = 'A';
    c[1] = 'Y';
    c[2] = 'U';
    c[3] = 'S';
    c[4] = 'H';

    int len = strlen(c);
    printf("String before null character = %s\n", c);
    printf("length before null character = %d\n", len);


    c[5] = '\0';
    int len_2 = strlen(c);
    printf("String after null character = %s\n", c);
    printf("length after null character = %d\n", len_2);

    char d[] = "AYUSH"; //Automatically null terminated.
    int size = sizeof(d);
    int len_3 = strlen(d);
    printf("length of string literal = %d\n", len_3);
    printf("Size of string = %d bytes\n", size);


    char e[6] = {'A','Y','U','S','H','\0'}; //define null termination implicitly
    int size_2 = sizeof(e);
    int len_4 = strlen(e);
    printf("length of string literal = %d\n", len_4);
    printf("Size of string = %d bytes\n", size_2);
    

    return 0;
}