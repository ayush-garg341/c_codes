// Handles the case for circular queue. 
#include<stdio.h>
#include<stdlib.h>
# define MAX_SIZE 100
int A[MAX_SIZE];
int front=-1;
int rear=-1;


int IsFull(){
  if((rear+1)%MAX_SIZE == front){
    return 1;
  }
  return 0; 
}

int IsEmpty(){
  if(front == -1 && rear == -1){
    return 1;
  }
  return 0;
}

void Enqueue(int x){
  if(IsFull()){
    printf("Element can not be queued since queue is full\n");
    return ;
  }
  if(IsEmpty()){
    front = rear = 0;
  }
  else{
    rear = (rear+1)%MAX_SIZE;
  }

  A[rear] = x;
}

void Dequeue(){
  if(IsEmpty()){
    printf("Queue is already empty, no element can be dequeued\n");
    return;
  }

  else if(front==rear){
    front = rear = -1;
  }
  
  else{
    front = (front + 1)%MAX_SIZE;
  }
}

int FrontElement(){
  if(front==-1){
    printf("Can not return front element from an empty queue\n");
    return -1;
  }
  return A[front];
}


void Print(){
  if(IsEmpty()){
    printf("Queue is empty\n");
  }
  else{
    int count = (rear-front+MAX_SIZE)%MAX_SIZE + 1;
    for(int i=0; i<count; i++){
      int index = (front+i) % MAX_SIZE;
      printf("%d ", A[index]);
    }

    printf("\n");
  }
}

int main(){
  Enqueue(2); // 2
  Enqueue(4); // 2 4
  Enqueue(6); // 2 4 6
  Enqueue(8); // 2 4 6 8 
  Enqueue(10); // 2 4 6 8 10
  Dequeue(); // 4 6 8 10
  Dequeue(); // 6 8 10
  Enqueue(1); // 6 8 10 1
  Enqueue(3); // 6 8 10 1 3
  
  Print(); // 6 8 10 1 3
}
