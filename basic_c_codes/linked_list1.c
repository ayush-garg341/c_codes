#include<stdio.h>
#include<stdlib.h>

int main(){
  struct node{
    int data;
    struct node* link;
  };

  printf("size of struct = %d\n", sizeof(struct node));
  struct node* head = NULL;
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
  printf("first node value = %d, second node value = %d\n", tmp->data, tmp1->data);
  printf("value of head node = %lu, address of first node = %lu\n", head, tmp);
  printf("link of first node = %lu, address of second node = %lu\n", tmp->link, tmp1);
  
}
