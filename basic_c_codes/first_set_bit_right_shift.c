#include<stdio.h>

int main(){
  int x = 19;
  int count = 0;
  while(((x >> count) & 1 ) == 0){
    count++;
  }

  printf("first set bit is %d\n", count+1);

  return 0;
}
