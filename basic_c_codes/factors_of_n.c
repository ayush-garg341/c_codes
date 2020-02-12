#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    int A = *((int*)a); // type-casting to integer pointer and getting value ( de-referencing ) 
    int B = *((int*)b);
    return A-B;
}

int main(){
    double n;
    printf("Enter the number to calculate factors..... \n");
    scanf("%lf", &n);

    int int_n = (int)n;
    int count = 0;

    double square_root = sqrt(n);

    int sq_root = (int)square_root;

    int *factor_arr = (int *)calloc(2*sq_root, sizeof(int));


    for(int i = 1; i <= sq_root; i++){
        if(int_n % i==0){
            *(factor_arr + count) = i;
            if(i <= sq_root && i!=int_n/i){
                *(factor_arr + count + 1) = int_n/i;
            }
        }
        count += 2;
    }

    qsort(factor_arr, 2*sq_root, sizeof(int) , compare);


    for(int j = 0; j < 2*sq_root; j++){
        if(factor_arr[j]!=0){
            printf("%d ", factor_arr[j]);
        }
    }

    printf("\n");

    free(factor_arr);

    return 0;
}