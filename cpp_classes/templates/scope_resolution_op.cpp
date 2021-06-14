#include<iostream>

using namespace std;

template <class T>
class MyClass{
  T data;
public:
  MyClass(T a){
    data = a;
  }

  void display();
};


template <class T>
void MyClass<T> :: display(){
  cout << "data == " << data << endl; 
}

template <class T>
void func(T data){
  cout << "I am parameterised func() " << data << "\n";
}

void func(int data){
  cout << "I am non-parameterised func() " << data << "\n";
}

int main(){
  MyClass<char> obj('s');
  obj.display();

  func(5);

  return 0;
}


// prefernece is given to exact match...
