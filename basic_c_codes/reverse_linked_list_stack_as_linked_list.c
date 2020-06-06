#include<stdio.h>
#include<stdlib.h>

// not much memory efficient since using linked list as stack implementation
// code for creating linked list

struct node{
  int data;
  struct node* link;
};

struct node* head = NULL;


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



void Print(){
  struct node* tmp_traverse = head;
  while(tmp_traverse!=NULL){
    printf("%d ", tmp_traverse->data);
    tmp_traverse = tmp_traverse->link;
  }
  printf("\n");
}


// code for creating stack linked list

struct stack_node{
  struct node* stack_data;
  struct stack_node* stack_link;
};

struct stack_node* stack_head=NULL;

void Push(struct node* x){
  struct stack_node* temp = (struct stack_node*)malloc(sizeof(struct stack_node));
  temp->stack_data=x;
  temp->stack_link=stack_head;
  stack_head=temp;
}

void Pop(){
  struct stack_node* temp;
  if(stack_head==NULL){
    return;
  }
  temp=stack_head;
  stack_head=stack_head->stack_link;
  free(temp);
}

struct node* Top(){
  return stack_head->stack_data;
}

int IsEmpty(){
  if(stack_head==NULL){
    return 1;
  }
  return 0;
}

void Traverse(){
  struct node* tmp_traverse = head;
  while(tmp_traverse!=NULL){
    Push(tmp_traverse);
    tmp_traverse = tmp_traverse->link;
  }
}


void Reverse(){
  struct node* tmp = Top();
  head=tmp;
  Pop();
  while(!IsEmpty()){
    tmp->link=Top();
    tmp=tmp->link;
    Pop();
  }
  tmp->link=NULL;
}

int main(){
  Insert(4); 
  Insert(6);
  Insert(8);
  Insert(10);
  Print(); // 4 6 8 10
  Traverse();
  Reverse();
  Print();
  
}
