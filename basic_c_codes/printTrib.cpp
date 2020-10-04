#include<iostream>

using namespace std;

int printTribRec(int n){
  if(n==0 || n==1 || n==2){
    return 0;
  }

  if(n==3){
    return 1;
  }

  else{
    return printTribRec(n-1) + printTribRec(n-2) + printTribRec(n-3); 
  }

}

int main(){
  int n = 6;
  for(int i=1; i <6; i++){
    cout << printTribRec(i) << " ";
  }
  return 0;
}
