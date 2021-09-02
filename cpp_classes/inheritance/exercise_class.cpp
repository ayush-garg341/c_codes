#include<iostream>
using namespace std;


class SimpleCalculator{
protected:
  int num1;
  int num2;
  int result;
  
public:
  void set_two_nums(int a, int b){
    num1 = a;
    num2 = b;
  }

  void add_two_nums(){
    result = num1 + num2;
  };

  void sub_two_nums(){
    result = num1 - num2;
  }

  void multiply_two_nums(){
    result = num1 * num2;
  }

  void divide_two_nums(){
    if(num2 == 0){
      cout << "Invalid: division by 0 can not be performed" << endl;
      return ;
    }
    result = num1 / num2;
  }


  void display(){
    cout << "The result of the calculation is " << result << endl;
  }
  
};


class ScientificCalculator: protected SimpleCalculator{

  public:
  void add_two_nums_scientifically(){
    cout << "syntific add" << endl;
    result = num1 + num2;
  };

  void sub_two_nums_scientifically(){
    cout << "syntific subtract" << endl;
    result = num1 - num2;
  }

  void multiply_two_nums_scientifically(){
    cout << "syntific multiply" << endl;
    result = num1 * num2;
  }

  void divide_two_nums_scientifically(){
    cout << "syntific divide" << endl;
    if(num2 == 0){
      cout << "Invalid: division by 0 can not be performed" << endl;
      return ;
    }
    result = num1 / num2;
  }
  
};


class HybridCalculator: public SimpleCalculator, public ScientificCalculator{
public:
  void display(){
    cout << "Inside Hybrid calculator" << endl;
  };
  
};


int main(){
  
  return 0;
}
