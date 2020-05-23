#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* link;
};

struct node* head = NULL;

void Push(int x){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data=x;
  temp->link=head;
  head=temp;
}

void Pop(){
  struct node* temp;
  if(head==NULL){
    return;
  }
  temp=head;
  head=head->link;
  free(temp);
}

int Top(){
  return head->data;
}

int IsEmpty(){
  if(head==NULL){
    return 1;
  }
  return 0;
}


void ReversePrint(struct node* head){
  if(head==NULL){
    return;
  }
  ReversePrint(head->link);
  printf("%d ", head->data);
}

 
int main(){
  Push(2);
  Push(4);
  Push(6);
  Pop();
  Push(8);
  Push(10);
  Pop();
  Push(12);
  ReversePrint(head);
  printf("\n");
}
