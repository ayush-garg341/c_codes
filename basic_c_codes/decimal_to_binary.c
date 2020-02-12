#include<stdio.h>

int main(){
    int bin[32], decimal_number, rem, count=0;
    printf("Enter the decimal number\n");
    scanf("%d", &decimal_number);

    while(decimal_number>0){
        rem = decimal_number % 2;
        bin[count] = rem;
        count++;
        decimal_number = decimal_number / 2;
    }

    printf("count = %d\n", count);
    
    for (int i = count-1; i >= 0; i--){
        printf("%d", bin[i]);
    }
    printf("\n");

    return 0;
}