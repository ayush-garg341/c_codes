#include<iostream>

using namespace std;

template <class MYTYPE>class MyClass{
  MYTYPE p1;
  MYTYPE p2;

public:
  MyClass(MYTYPE x, MYTYPE y){
    p1 = x;
    p2 = y;
  }

  void printValues(){
    cout << "values p1 = " << p1 << " and p2 " << p2 << endl;
  };
};


int main(){
  MyClass<int> intObject(22, 30);
  MyClass<string> stringObject("Ayush", "Garg");

  intObject.printValues();
  stringObject.printValues();
  
  return 0;
}
