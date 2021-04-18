#include<stdio.h>

int main(){
  int x = 18;
  int count = 0;
  while((x & (1 << count)) == 0 ){
    count++;
  }
  printf("first set bit is %d\n", count+1);
  return 0;
}
