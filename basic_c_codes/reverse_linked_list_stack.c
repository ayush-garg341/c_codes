#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int top=-1;

struct node{
  int data;
  struct node* link;
};

struct node* head;

struct node* A[MAX_SIZE];

void Push(struct node* x){
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

void Insert(int data){
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data=data;
  tmp->link=NULL;
  if(head==NULL){
    head=tmp;
    return;
  }
  struct node* tmp_traverse = head;
  while(tmp_traverse->link!=NULL){
    tmp_traverse = tmp_traverse->link;
  }
  tmp_traverse->link=tmp;
};


void Reverse(){
  struct node* tmp = A[top];
  head=tmp;
  Pop();
  while(top!=-1){
    tmp->link=A[top];
    tmp=tmp->link;
    Pop();
  }
  tmp->link=NULL;
  
}

void Print(){
  struct node* tmp_traverse = head;
  while(tmp_traverse!=NULL){
    printf("%d ", tmp_traverse->data);
    tmp_traverse = tmp_traverse->link;
  }
  printf("\n");
}

void Traverse(){
  struct node* tmp_traverse = head;
  while(tmp_traverse!=NULL){
    Push(tmp_traverse);
    tmp_traverse = tmp_traverse->link;
  }
}

int main(){
  head=NULL;
  Insert(4); 
  Insert(6);
  Insert(8);
  Insert(10);
  Insert(14);
  Print(); // 4 6 8 10
  Traverse(); // traverses the linkedlist
  Reverse();
  Print(); // 10 8 6 4
  
}
