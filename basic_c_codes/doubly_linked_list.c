#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* head; // global-variable pointer to head node.

struct Node* GetNewNode(int x){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data=x;
  temp->next=NULL;
  temp->prev=NULL;
  return temp;
}

void InsertAtHead(int x){
  struct Node* temp = GetNewNode(x);
  temp->next=head;
  if(head==NULL){ 
    head=temp;
    return;
  }
  head->prev=temp;
  head=temp;
  return;
}

void Print(){
  struct Node* temp = head;
  printf("forward: ");
  while(temp!=NULL){
    printf("%d ", temp->data);
    temp=temp->next;
  }
  printf("\n");
}

void ReversePrint(){
  struct Node* temp=head;
  if(temp==NULL)return;

  // Going to last node
  while(temp->next!=NULL){
    temp=temp->next;
  }

  // Traversing backward using reverse pointer.
  printf("Reverse Print: ");
  while(temp!=NULL){
    printf("%d ", temp->data);
    temp=temp->prev;
  }
  printf("\n");
}

int main(){
  head=NULL;
  InsertAtHead(2);
  InsertAtHead(4);
  InsertAtHead(6);
  InsertAtHead(8);
  Print();
  ReversePrint();
}


// Anything in heap/dynamic memory is not cleared, unless we clear/remove it explicitly.
// We can also define
// struct Node temp;
// temp.data=x; temp.prev=NULL; temp.next=NULL
// But the problem is, above variable temp is local variable and gets created in the stack section of memeory and as soon as function call finishes, it is cleared from the memory and this is not we want// We can not control allocation and de-allocation of memory on stack.
