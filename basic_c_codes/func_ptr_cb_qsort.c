#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    int A = *((int*)a); // type-casting to integer pointer and getting value ( de-referencing ) 
    int B = *((int*)b);
    return B-A;
}

int main(){
    int i, A[] = {-2,4,3,-7,5,-6};
    qsort(A, 6, sizeof(int) , compare); // qsort can sort any type of array thats why comprisn functn is passed generic/void pointer for typecasting later.
    for(i = 0; i < 6; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}