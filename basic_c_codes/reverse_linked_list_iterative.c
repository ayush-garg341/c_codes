#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* head;

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
  struct node *tmp, *prev, *next;
  prev=NULL;
  tmp=head;
  while(tmp!=NULL){
    next=tmp->link;
    tmp->link = prev;
    prev=tmp;
    tmp=next;
  }
  head=prev;
}

void Print(){
  struct node* tmp_traverse = head;
  while(tmp_traverse!=NULL){
    printf("%d ", tmp_traverse->data);
    tmp_traverse = tmp_traverse->link;
  }
  printf("\n");
}

int main(){
  head=NULL;
  Insert(4); 
  Insert(6);
  Insert(8);
  Insert(10);
  Print(); // 4 6 8 10
  Reverse();
  Print(); // 10 8 6 4
}
