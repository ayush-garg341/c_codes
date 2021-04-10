#include<stdio.h>

int minNumFlips(int a, int b, int c){

  int numFlips = 0;
  
  while(c>0){
    int rightA = a & 1;
    int rightB = b & 1;
    int rightC = c & 1;
    if((rightA | rightB) == rightC){
      a >>= 1;
      b >>= 1;
      c >>= 1;
      continue;
    }
    else if(rightC == 0 && ((rightB==1 && rightA ==0) || (rightB==0 && rightA==1))){
      numFlips += 1;
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    else if(rightC == 0 && (rightB==1 && rightA ==1)){
      numFlips += 2;
      a >>= 1;
      b >>= 1;
      c >>= 1;
    }
    else if(rightC == 1 && (rightB == 0 && rightA == 0)){
      a >>= 1;
      b >>= 1;
      c >>= 1;
      numFlips += 1;
    }
  }
  return numFlips;
}

int main(){
  int a = 2;
  int b = 6;
  int c = 5;
  int numFlips = minNumFlips(a, b, c);
  printf("%d number of flips required to make %d | %d == %d \n", numFlips, a, b, c);
  return 0;
}
