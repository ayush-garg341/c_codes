#include<stdio.h>

int main(){
  int x = 8;
  int bitCounter = 0;
  while((1 << bitCounter) <= x ){
    bitCounter += 1;
  }

  printf("number has %d bits\n", bitCounter);
  
  return 0;
}
