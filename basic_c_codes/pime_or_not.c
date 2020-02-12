#include<stdio.h>
#include"math.h"

int main(){
    double n;
    printf("Enter the number you want to check for prime\n");
    scanf("%lf\n", &n);

    double square_root;
    square_root = sqrt(n);

    printf("%lf\n", square_root);

    int sq_root = (int)square_root;

    printf("%d integer square root\n", sq_root);

    int int_num = (int)n;

    for(int i = 2; i <= sq_root; i++){
        if(int_num % i == 0){
            printf("%lf is not a prime number\n", n);
            return 0;
        }
    }

    printf("%lf is a prime number\n", n);

    return 0;
}