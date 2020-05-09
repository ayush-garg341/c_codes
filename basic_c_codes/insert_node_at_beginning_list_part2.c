#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* head; // global variables can be accessed anywhere

void Insert(int x){
  struct node* tmp = (struct node*)malloc(sizeof(struct node));
  tmp->data=x;
  tmp->link=head;
  head=tmp;
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
  printf("How many numbers ?\n");
  int n, i, x;
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("Enter the number\n");
    scanf("%d", &x);
    Insert(x);
    Print();  
  }
}

// Modifications we can make in the program
// 1. Instead of using head as global variable outside main, we can define it inisde main.
//    But then need to pass head as argument to insert and  return head from insert to get updated head and pass it to Print()
// 2. Second modification is instead of returning around head from local functions, pass the address of head node to insert() i.e. &head and recieve as Node** pointerTOHead in the insert args.  
