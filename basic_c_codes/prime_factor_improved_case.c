#include<stdio.h>
#include<math.h>

int main(){
    double n;
    printf("Enter the number to find prime factors:\n");
    scanf("%lf", &n);

    int flag = 0;

    int int_n = (int)n; 

    int i, loop_check = (int)sqrt(n);

    for(i = 2; i <= loop_check; i++){
        int count = 0;
        if(int_n%i==0){
            while(int_n%i==0){
                int_n = int_n/i;
                count++;
            }
            printf("(%d, %d)\n", i, count);
            flag = 1;
        }

        else if(i > (int)sqrt((double)int_n)){
            printf("(%d, %d)\n", int_n, 1);
            flag = 1;
            return 0;
        }
    }

    if(flag==0){
        printf("%d is already a prime number\n", int_n);
    }

    return 0;
}