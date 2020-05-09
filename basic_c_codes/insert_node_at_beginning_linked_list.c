#include<stdio.h>
#include<stdlib.h>

int main(){
  
  struct node{
    int data;
    struct node* link;
  };
  printf("size of struct = %d\n", sizeof(struct node));
  struct node* head = NULL; // empty list
  printf("address size = %lu\n", sizeof(head));
  struct node* tmp = (struct node *)malloc(sizeof(struct node));
  head=tmp;
  (*tmp).data = 2;
  (*tmp).link = NULL;

  struct node* tmp1 = (struct node *)malloc(sizeof(struct node));
  tmp1->data = 4;
  tmp1->link = NULL;
  
  struct node* tmp3 = head;
  while(tmp3->link!=NULL){
    tmp3 = tmp3->link;
  }
  tmp3->link=tmp1;

  // sizeof operator gives size in "bytes"
  // upto here we have linked list 2 4
  // Now implement to insert node at beginning i.e something like 1 2 4

  struct node* begin_node = (struct node *)malloc(sizeof(struct node));
  begin_node->data = 1;
  struct node* temp_node = head;
  head = begin_node;
  begin_node->link = temp_node;

  struct node* temp_traverse = head;
  while(temp_traverse->link!=NULL){
    printf("%d ", temp_traverse->data);
    temp_traverse=temp_traverse->link;
  }
  printf("%d\n", temp_traverse->data);
}
