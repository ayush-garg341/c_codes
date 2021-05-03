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
  int i = 0;
  int j = midPoint + 1;
  int high = size-1;
  int k = 0;
  int auxArr[size/2];
  while(k<size/2){
    if(A[i] < A[j]){
      auxArr[k] = A[i];
      k++; i++;
    }
    else{
      auxArr[k] = A[j];
      k++;
      j++;
    }
  }

  int mergePoint = midPoint + 1;
  int count = 0;
  while(i<=midPoint){
    A[mergePoint] = A[i];
    mergePoint++;
    i++;
    count++;
  }

  i = 0;
  while(i<=midPoint){
    A[i] = auxArr[i];
    i++;
  }

  PrintArray(A, size);
  
  
  int mid = midPoint + count ;
  int low = midPoint + 1;
  i = midPoint + 1;
  k = 0;
  
  while(i <= mid && j <= high){
    if(A[j] < A[i]){
      auxArr[k++] = A[j++];
    }
    else {
      auxArr[k++] = A[i++];
    }
  }

  while(i<=mid){
    auxArr[k++] = A[i++];
  }

  while(j<=high){
    auxArr[k++] = A[j++];
  }

  for(i=high; i >= low; i--)
    {
        A[i] = auxArr[--k];  
    }
  
}

int main(){
  int A[] = {1, 2, 3};
  //int A[] = {10, 5, 30, 23, 21, 49, 32, 99};
  int high = sizeof(A)/sizeof(int);
  if(high==0){
    printf("empty arrray passed\n");
    return 0;
  }
  else if(high%2!=0){
    printf("array must be of even size\n");
    return 0;
  }
  Merge(A, high);
  PrintArray(A, high);
  return 0;
}
