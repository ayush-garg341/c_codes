#include<stdio.h>
#include<string.h>


int main(){
  char c[50];
  printf("Enter the string ");
  gets(c);
  int len = strlen(c);
  int start = 0;
  int end = len-1;
  int half = (int)(len/2);
  char tmp;
  for(int i = 0; i<half; i++){
    if(start<end){
      tmp=c[end];
      c[end]=c[start];
      c[start]=tmp;
      start++;
      end--;
    }
  }

  printf("reversed string = %s\n", c);
}
