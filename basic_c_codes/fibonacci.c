#include<stdio.h>

int fib(int n){
  if(n<=1){
    return n;
  }
  return fib(n-1) + fib(n-2);
}

int main(){
  int num;
  num = fib(6);
  printf("%d\n", num);
  return 0;
}
