#include<stdio.h>

int main(){
  int n = 10;
  int k = 2;

  int newNum = 1 << (k-1);

  if((newNum | n )== n){
    printf("%dth bit is set\n", k);
  }
  else{
    printf("%dth bit is not set\n", k);
  }
  return 0;
}
