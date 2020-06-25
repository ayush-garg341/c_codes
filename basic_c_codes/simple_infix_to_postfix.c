#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
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


int Top(){
  if(top==-1){
    printf("Error: stack is empty\n");
    return 0;
  }
  return A[top]; 
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	}
	return weight;
}

int IsHigherPrecedence(char a, char b){
  int op1 = GetOperatorWeight(a);
  int op2 = GetOperatorWeight(b);
  if(op1>=op2){
    return 1;
  }

  return 0;
}

void InfixToPostfix(char *s, int n){
  char c[100];
  int count = 0;
  for(int i=0; i<n; i++){
    if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i]=='/'){
      while(top!=-1 && IsHigherPrecedence(A[top], s[i])){
	c[count] = A[top];
	count+=1;
	Pop();
      }
      top+=1;
      A[top] = s[i];
    }

    else {
      c[count] = s[i];
      count += 1;
    }
  }

  while(top!=-1){
    c[count] = Top();
    count +=1;
    Pop();
  }


  for (int j=0; j<strlen(c);j++){
    printf("%c", c[j]);
  }

  printf("\n");
  
}

int main() {
  char s[100];
  printf("Enter the expression: ");
  gets(s);
  printf("string length = %d\n", strlen(s));
  InfixToPostfix(s, strlen(s));
  
}
