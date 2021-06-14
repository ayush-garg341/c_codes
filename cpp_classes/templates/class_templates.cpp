#include<iostream>

using namespace std;

template <class T1 , class T2>
class MyClass{
  T1 a;
  T2 b;
public:
  MyClass(T1 x, T2 y){
    a = x;
    b = y;
  }

  void display(){
    cout << "a = " << a << " b= " << b << "\n";
  }
};
    

int main(){
  MyClass<int , char> obj(6, 'a');
  obj.display();
  return 0;
}
