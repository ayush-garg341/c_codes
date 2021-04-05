#include<stdio.h>

int main(){

  int num = 100;
  int copiedNum = num;
  int count = 0;
  while(num!=0){
    int rsbm = num & -num;
    num = num - rsbm;
    count ++;
  }

  printf("number %d has %d set bits\n", copiedNum, count);
  
  return 0;
}
