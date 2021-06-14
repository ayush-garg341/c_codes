#include<iostream>

using namespace std;

template <class T>
void swapCustom(T &a, T &b){
  T temp = a;
  a = b;
  b = temp;
}


template <class T1, class T2>
float average(T1 a, T2 b){

  float avg = (a+b)/2.0;
  return avg;
  
}


int main(){
  int num1 = 10;
  int num2 = 20;
  cout << "before swap num1 and num2  " << num1 << " "  << num2 << "\n";

  swapCustom(num1, num2);

  cout << "after swap num1 and num2 " << num1 << " " << num2 << "\n";

  
}
