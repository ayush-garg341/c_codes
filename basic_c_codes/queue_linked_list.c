#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;

int IsEmpty(){
  if(front==NULL){
    return 1;
  }
  return 0;
}

void Enqueue(int x){
  struct node* tmp = (struct node*)malloc(sizeof(struct node*));
  tmp->data = x;
  tmp->next=NULL;
  if(front==NULL && rear==NULL){
    front=rear=tmp;
    return;
  }
  rear->next=tmp;
  rear=tmp;
}

void Dequeue(){
  struct node* tmp = front;
  if(front==NULL){
    printf("Queue is empty, on element to dequeue\n");
    return;
  }
  if(front==rear){
    front=rear=NULL;
  }
  else{
    front=front->next;
  }
  free(tmp);
}

void Print(){
  if(front==NULL){
    printf("Queue is empty\n");
    return;
  }
  while(front!=NULL){
    printf("%d ", front->data);
    front = front->next;
  }
  printf("\n");
}

 
int main(){
  Enqueue(2);//2
  Enqueue(4);//2 4
  Enqueue(5);// 2 4 5
  Enqueue(7);// 2 4 5 7
  Enqueue(8);// 2 4 5 7 8
  Dequeue();// 4 5 7 8
  Dequeue();// 5 7 8
  Dequeue();// 7 8
  Enqueue(10);// 7 8 10
  Enqueue(21);// 7 8 10 21
  Print();// 7 8 10 21
}
