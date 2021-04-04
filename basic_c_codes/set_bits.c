#include<stdio.h>

int main(){
  int num = 140;
  int copied_num = num;
  int set_bits_count = 0;
  while(num > 0){
    if((num & 1)==1){
      set_bits_count += 1;
    }
    num = num >> 1;
  }

  printf("No of set bits in %d = %d \n", copied_num, set_bits_count);
  
  return 0;
}
