#include<stdio.h>
#include<math.h>


int main(){
  int num_arr[] = {1,2,4};
  int array_size = sizeof(num_arr)/sizeof(int);
  int num_sub_set = pow(2, array_size);
  
  for(int i=0; i< num_sub_set; i++){
    for(unsigned int j = 0; j < sizeof(num_arr); j++){
      if((i & (1 << j)) != 0 ){
	printf("[%d]", num_arr[j]);
      }
    }
    printf("\n");
  }
  
  
  return 0;
}
