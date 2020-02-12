#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of an array\n");
    scanf("%d", &n);
    int *A = (int *)malloc(n*sizeof(int)); // dynamically allocated array, with intial garbage value

    int *B = (int *)calloc(n, sizeof(int)); // intialize values with zero

    for (int i = 0; i < n; i++){
        A[i] = i+1;
    }

    for(int i = 0; i < n; i++){
        printf('%d ', A[i]);
    }

    // int *B = (int *)realloc(A, 0);  equivalent to free(A)
    // int *B = (int *)realloc(NULL, n*sizeof(int)); equivalent to malloc, does not copy anything from previous block.
    // int *B = (int *)realloc(A, 2*n*sizeof(int));  reallocates the memory for 2*n elements with n elements already there from A

    return 0;
}