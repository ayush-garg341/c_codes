#include<stdio.h>

int main(){
  int a = 100;
  int b = 23;
  int c = a ^ b;
  if(c < 0){
    printf("Numbers are opposite sign\n");
  }
  else{
    printf("Numbers are same sign\n");
  }
  
  return 0;
}
