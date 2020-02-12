#include<stdio.h>


//  int A[] is interpreted as int *A by the compiler i.e. pointer to integer and hence arrays are always passed as pointer to first element of array.

int SumOfElements(int A[]){
    int i, sum = 0;
    int size = sizeof(A)/sizeof(A[0]);
    printf("SOE - A = %d, A[0] = %d\n", A, A[0]);
    printf("SOE - size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    for (i = 0; i < size; i++){
        sum += A[i];

    }

    return sum;
}

int main(){
    int A[] = {1,2,3,4,5};
    int total = SumOfElements(A);
    printf("Sum of elements = %d\n", total);
    printf("Main - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    return 0;
}