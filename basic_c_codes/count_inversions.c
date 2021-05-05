/* pair is an inversion if i < j but a[i] > a[j] */

#include<stdio.h>
#include<stdlib.h>

int count_inversion = 0;

void Sort(int A[], int low, int mid, int high, int size){

  int auxArr[size];
  int k = 0;
  int i = low;
  int j = mid + 1;
  
  while(i <= mid && j <= high){
    if(A[j] < A[i]){
      auxArr[k++] = A[j++];
      count_inversion += mid + 1 - i;
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


void MergeSort(int A[], int low, int high, int size){
  if(low < high){
    int mid = (low + high)/2;
    MergeSort(A, low, mid, size);
    MergeSort(A, mid+1, high, size);
    Sort(A, low, mid, high, size);
  }
}

int main(){
  // int A[] = {8, 4, 2, 1};
  int A[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int low = 0;
  int high = sizeof(A)/sizeof(int);
  MergeSort(A, low, high-1, high);
  printf("number of inversion = %d\n", count_inversion);
  return 0;
}
