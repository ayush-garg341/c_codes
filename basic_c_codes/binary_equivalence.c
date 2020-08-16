#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

int COUNT = 0;

char* FindBinaryWithPadding(int num, int max_binary_digits){
  char* binary_array;
  binary_array = (char*)malloc(max_binary_digits*1);
  int count = max_binary_digits-2;
  int j, rem, i;
  for(j=0; j<max_binary_digits-1; j++){
    binary_array[j]='0';
  }
  binary_array[j]='\0';

  while(num!=0){
    rem = num % 2;
    num /= 2;
    i *= 10;
    if(rem==0){
      binary_array[count] =  '0';
    }
    else {
      binary_array[count] =  '1';
    }
    count = count - 1;
  }

  return binary_array;
  
}


int FindMaxBinaryDigits(int max_num){
  int rem, i = 1, count=0;
  while (max_num != 0) {
    count += 1;
    rem = max_num % 2;
    max_num /= 2;
    i *= 10;
  }
  return count;
}

int FindMax(int arr[], int num_elements){
  int max=0;
  for(int i = 0; i< num_elements; i++){
    if(arr[i]>=max){
      max = arr[i];
    }
  }
  return max;
};


int main(){
  int num_elements;
  int num_array[MAX_SIZE];
  int max_binary_digits;

  printf("Input\n");
  
  scanf("%d\n", &num_elements);

  for(int i=0; i<num_elements; i++){
    scanf("%d", &num_array[i]);
  }
  printf("\n");

  int max_in_array = FindMax(num_array, num_elements);

  max_binary_digits = FindMaxBinaryDigits(max_in_array);
  
  char* binary_char_array[num_elements][max_binary_digits+1];

  for (int j=0; j<num_elements; j++){
    *binary_char_array[j] = FindBinaryWithPadding(num_array[j], max_binary_digits+1);
  }

  for (int i=0; i <num_elements; i++) 
    { 
      
      for (int j=i; j<num_elements; j++)  
	{
	  
	  int sub_count = 0;
	  int zero_count = 0;
	  int one_count = 0;
	  char* binary_char_sub_array[num_elements][max_binary_digits+1];
	  for (int k=i; k<=j; k++) 
	  {
	     sub_count += 1;
	     *binary_char_sub_array[sub_count-1] = *binary_char_array[k];
	  }

	  for(int l=0; l<sub_count; l++){
	    char* temp_char = *binary_char_sub_array[l];
	    for(int n = 0; n<max_binary_digits; n++){ 
	      if(temp_char[n]=='0'){
	      	zero_count+=1;
	      }
	      else {
	      	one_count += 1;
	      }
	    }
	  }
	  if(zero_count==one_count){
	    COUNT+=1;
	  }
	  
	}
    }
  printf("Output\n");
  printf("%s\n", FindBinaryWithPadding(COUNT, max_binary_digits+1));
  
  return 0;
}
