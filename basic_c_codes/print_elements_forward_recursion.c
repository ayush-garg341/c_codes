#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* Insert(struct node* head, int data){
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data=data;
  tmp->link=NULL;
  if(head==NULL){
    head=tmp;
    return head;
  }
  struct node* tmp_traverse = head;
  while(tmp_traverse->link!=NULL){
    tmp_traverse = tmp_traverse->link;
  }
  tmp_traverse->link=tmp;

  return head;
};


void Print(struct node* head){
  if(head!=NULL){
    printf("%d ", head->data);
    Print(head->link);
  }
  else{
    return;
  }
}

int main(){
  struct node *head=NULL;
  head = Insert(head,4); 
  head = Insert(head,6);
  head = Insert(head,8);
  head = Insert(head,10);
  Print(head);
  printf("\n");
}
