#include<stdio.h>

int main(){
    int n;
    printf("Enter the number to find prime factors:\n");
    scanf("%d", &n);

    int i, loop_check = n;

    for(i = 2; i < loop_check; i++){
        int count = 0;
        if(n%i==0){
            while(n%i==0){
                n = n/i;
                count++;
            }
            printf("(%d, %d)\n", i, count);
        }
    }

    if(i==loop_check && n!=1){
        printf("Number is already prime\n");
    }

    return 0;
}