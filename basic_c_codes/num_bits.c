#include<stdio.h>

int main(){

  int num = 125;
  int bitsCounter = 0;
  while((1 << bitsCounter) <= num ){
    bitsCounter ++;
  }

  printf("%d has %d number of bits \n", num, bitsCounter);
  return 0;
}
