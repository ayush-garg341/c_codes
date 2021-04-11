#include<stdio.h>

int main(){
  int a[] = {4, 3, 3, 4, 4, 4, 5, 3, 5};
  int num=0;
  for(unsigned int i=0; i < sizeof(a)/sizeof(int); i++){
    num = num ^ a[i];
  }

  printf("The element that is repeated odd number of times is %d\n", num);
  
  return 0;
}
