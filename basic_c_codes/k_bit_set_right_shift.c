#include<stdio.h>

int main(){
  int x = 18;
  int k = 1;
  if(((x >> (k-1))&1) == 1){
    printf("%dth bit is set\n", k);
  }
  else{
    printf("%dth bit is not set\n", k);
  }
  return 0;
}
