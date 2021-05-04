#include<stdio.h>
#include<stdlib.h>

void PrintArray(int A[], int size){
  for(int i=0; i<size; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}


void Merge(int A[], int size){
  int midPoint = (size-1)/2;
  int aux[size/2];
  int i;
  int j = midPoint + 1;
  int high = size -1;
  for(i=0; i<=midPoint;i++){
    aux[i] = A[i];
  }

  i = 0;
  int k = 0;
  
  while(i <= midPoint && j <= high){
    if(A[j] < aux[i]){
      A[k++] = A[j++];
    }
    else {
      A[k++] = aux[i++];
    }
  }

  while(i<=midPoint){
    A[k++] = aux[i++];
  }

  while(j<=high){
    A[k++] = A[j++];
  }
  
}



int main(){
  //int A[] = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
  int A[] = {1, 3, 6, 8, 10, 2, 5, 7, 9};
  int high = sizeof(A)/sizeof(int);
  Merge(A, high);
  PrintArray(A, high);
  return 0;
}
