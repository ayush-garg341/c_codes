#include<stdio.h>
#include"math.h"
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the numbers to find primes upto\n");
    scanf("%d", &n);

    int *primes_arr = (int *)malloc((n+1)*sizeof(int));

    *primes_arr = 1;

    for(int i = 1; i <= n; i++){
        *(primes_arr+i) = 1;
    }

    double square_root = sqrt(n);

    int sq_root = (int)square_root;

    for(int j = 2; j <= sq_root; j++){ 
        for(int k = 2; j*k <= n; k++){
            primes_arr[j*k] = 0;
        }
    }

    /*
    for j=2, all the 2 factors are not prime and hence innner loop will run n/2 times
    for j=3, all the 3 factors are not prime and hence innner loop will run n/3 times
    for j=5, all the 5 factors are not prime and hence innner loop will run n/5 times
    series will be something like
    n/2 + n/3 + n/5 + n/7 + n/9 + ......

    */


    printf("prime numbers upto %d are ........\n", n);

    for( int i = 2; i <= n ; i++){
        if(primes_arr[i]==1){
            printf("%d ", i);
        }
    }

    printf("\n");

    free(primes_arr);

    return 0;
}