#include<string.h>
#include<stdio.h>

#define MAX_SIZE 101
char A[MAX_SIZE];
int top=-1;

void Push(int x){
  if(top==MAX_SIZE-1){
    printf("Error: stack Overflow\n");
    return;
  }
  top+=1;
  A[top] = x;
}

void Pop(){
  if(top==-1){
    printf("Error: No element to pop\n");
    return;
  }
  top--;
}

void Reverse(char *c, int n){
  for(int i=0; i<n; i++){
    Push(c[i]);
  }

  for(int i=0; i<n; i++){
    c[i] = A[top];
    Pop();
  }
}

int main(){
  char c[51];
  printf("Enter a string ");
  gets(c);
  printf("string length = %d\n", strlen(c));
  Reverse(c, strlen(c));
  printf("output = %s\n", c);
}
