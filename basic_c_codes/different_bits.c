#include<stdio.h>

int main(){
  int x = 12;
  int y = 15;
  int count = 0;
  while(x > 0){
    int right_most_x = x & 1;
    int right_most_y = y & 1;
    count += right_most_x ^ right_most_y;
    x = x >> 1;
    y = y >> 1;
  }

  printf("number of different bits are %d\n", count);
  
  return 0;
}
