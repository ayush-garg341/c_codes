#include<stdio.h>

int main(){

  int nums[] = {1,2,3,4,5,7,8,9};
  int res = 0;
  unsigned int array_size = sizeof(nums)/sizeof(int);
  for(unsigned int j = 0; j < array_size + 1; j++){
    res ^= j+1;
  }
  
  for(unsigned int i = 0; i < array_size; i++){
    res ^=  nums[i]; 
  }

  printf("missing element is %d\n", res);
  
  return 0;
}
