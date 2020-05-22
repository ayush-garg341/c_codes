#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct Stack{
  char stk[MAX];
  int top;
}s;

void push(char item){
  if(s.top==MAX-1){
    printf("stack is full \n");
    return;
  }
  s.top+=1;
  s.stk[s.top]=item;
}

void pop(){
  if(s.top==-1){
    printf("Stack is empty \n");
    return;
  }
  s.top -= 1;
}

int main(){
  char exp[MAX];
  int i = 0;
  s.top=-1;
  printf("\nInput the expression: ");
  scanf("%s", exp);
  for(i=0; i < strlen(exp); i++){
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
      push(exp[i]);
      continue;
    }
    else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
      if(exp[i]==')'){
	if(s.stk[s.top]=='('){
	  pop();
	}
	else{
	  printf("Unbalanced Parenthesis \n");
	  break;
	}
      }
      if(exp[i]=='}'){
	if(s.stk[s.top]=='{'){
	  pop();
	}
	else{
	  printf("Unbalanced Parenthesis \n");
	  break;
	}
      }
      if(exp[i]==']'){
	if(s.stk[s.top]=='['){
	  pop();
	}
	else{
	  printf("Unbalanced Parenthesis \n");
	  break;
	}
      }
    }
  }

  if(s.top==-1){
    printf("Balanced Parenthesis \n");
  }
  else{
    printf("Unbalanced parenthesis \n");
  }
}
