#include<stdio.h>
#include<stdlib.h>

int main(){
  int *ptr;
  ptr = (int *) malloc(2*sizeof(int));
  if(ptr==NULL){
    printf("Memory could not be allocated \n");
  }
  else{
    printf("Memory allocation successfully \n");
  }
  return 0;
}
