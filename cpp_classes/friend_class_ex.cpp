#include<iostream>
using namespace std;

// forward declaration
class c2;


class c1{
  int num1;
  friend void exchange(c1&, c2&);
public:
  void inData(int data){
    num1 = data;
  }

  void display(){
    cout << "The num in c1 " << num1 << endl;
  }
};


class c2{
  int num2;
  friend void exchange(c1&, c2&);
public:
  void inData(int data){
    num2 = data;
  }

  void display(){
    cout << "The num in c2 " << num2 << endl;
  }
};


void exchange(c1& o1, c2& o2){
  int temp = o1.num1;
  o1.num1 = o2.num2;
  o2.num2 = temp;
}


int main(){
  c1 o1;
  c2 o2;
  o1.inData(4);
  o2.inData(8);

  exchange(o1, o2);
  
  cout << "after swapping " << endl;
  o1.display();
  o2.display();
  
  return 0;
}
