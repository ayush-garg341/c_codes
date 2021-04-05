#include<stdio.h>

int isTwoPow(int num){
  int bit_set_count = 0;
  while(num!=0){
    bit_set_count += (num & 1);
    num = num >> 1;
  }

  return bit_set_count == 1 ? 1 : 0;
}

int main(){
  int num = 1;
  int return_val = isTwoPow(num);
  if(return_val){
    printf("number %d is a power of 2\n", num);
  }
  else{
    printf("number %d is not a power of 2\n", num);
  }
  
  return 0;
}
