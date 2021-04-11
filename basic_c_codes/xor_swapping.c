#include<stdio.h>

int main(){
  int a = 10;
  int b = 20;
  printf("Before swapping the value of a=%d and b=%d\n", a , b);
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  printf("After swapping the value of a=%d and b=%d\n", a, b);
  return 0;
}
