#include<stdio.h>

int main(){
    int a = 1025;
    int *p;
    p = &a;
    int size_int = sizeof(int);
    int size_char = sizeof(char);

    printf("size of integer is %d bytes\n", size_int);
    printf("Address = %d, value = %d\n", p, *p);
    // printf("Address = %p, value = %d\n", p, *p);
    printf("Address = %d, value = %d\n", p+1, *(p+1));

    char *p0;
    p0 = (char*)p; // typecasting
    printf("size of char is %d bytes\n", size_char);
    printf("Address = %d, value = %d\n", p0, *p0);
    // printf("Address = %p, value = %d\n", p0, *p0);
    printf("Address = %d, value = %d\n", p0+1, *(p0+1));

    // Void pointer - Generic pointer ( it does not point to any particular data type, pointer arithmetic not possible )
    void *p1;
    p1 = p;
    printf("Void pointer Address = %d\n", p1);
    // printf("Address = %d\n", p1+1, *p1); give error

    return 0;
}