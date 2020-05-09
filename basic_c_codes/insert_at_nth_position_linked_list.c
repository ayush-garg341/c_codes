#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* link;
};

struct node* head;

void Insert(int data, int n){
  int i;
  struct node* tmp = (struct node *)malloc(sizeof(struct node));
  tmp->data=data;
  tmp->link=NULL;
  if(n==1){
    tmp->link=head;
    head=tmp;
    return;
  }

  struct node* tmp_1 = head;
  for(i=0; i<n-2; i++){
    tmp_1=tmp_1->link;
  }
  tmp->link=tmp_1->link;
  tmp_1->link=tmp;
  
}

void Print(){
  struct node* tmp_traverse=head;
  while(tmp_traverse!=NULL){
    printf("%d ", tmp_traverse->data);
    tmp_traverse=tmp_traverse->link;
  }
  printf("\n");
}

int main(){
  head=NULL;
  Insert(2,1); // List: 2
  Insert(3,2); // List: 2 3
  Insert(4,1); // List: 4 2 3
  Insert(5,2); // List: 4 5 2 3
  Print();
}
