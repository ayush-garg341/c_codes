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

void Print(){
  struct node* tmp_traverse = head;
  while(tmp_traverse!=NULL){
    printf("%d ", tmp_traverse->data);
    tmp_traverse=tmp_traverse->link;
  }
  printf("\n");
};

void Delete(int n){
  int i;
  struct node* tmp_traverse = head;
  if(n==1){
    head=tmp_traverse->link;
    free(tmp_traverse);
    return;
  }

  for(i=0; i < n-2; i++){
    tmp_traverse = tmp_traverse->link;
  }
  struct node* remove_node = tmp_traverse->link;
  tmp_traverse->link = remove_node->link;
  free(remove_node);
};

int main(){
  head=NULL;
  Insert(4); 
  Insert(6); 
  Insert(8); 
  Insert(10);
  Print(); // 4 6 8 10
  Delete(3); // delete at position 3
  Print();  // 4 6 10
}
