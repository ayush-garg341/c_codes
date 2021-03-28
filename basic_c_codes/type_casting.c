#include<stdio.h>

int main(){
  int n = 30;
  void *ptr = &n;
  printf("%d\n", *(int *)ptr);
  printf("%c\n", *(char *)ptr);
  
  return 0;
}
