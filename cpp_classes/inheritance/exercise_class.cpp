#include<iostream>
#include<cmath>
using namespace std;


/*
  Create 2 classes:
    1. SimpleCalculator :- take input of two numbers using a utility function and performs +, -. *, / and displays the result
      using another function.

    2. ScientificCalculator :- Take input of two numbers using a utitlity function and performs four scientific ops. of your choice
      and displays the result using another function.

    
    3. Create Another class HybridCalculator and inherit it using these 2 classes

      1. What type of inheritance you are using ? -> Multiple inheritance 
      2. What mode of inheritance you are using ? -> public
      3. How is code re-usability implemented ?
      4. Create an object of HybridCalculator and displays result of simple and scientific calculator.

*/


class SimpleCalculator{
  int a;
  int b;
  
public:
  void get_data_simple(){
    cout << "Enter the value of a " << endl;
    cin >> a;
    cout << "Enter the value of b" << endl;
    cin >> b;
  }

  void performOpsSimple(){
    cout << "The value of a+b is " << a+b << endl;
    cout << "The value of a-b is " << a-b << endl;
    cout << "The value of a*b is " << a*b << endl;
    cout << "The value of a/b is " << a/b << endl;
  }
  
};


class ScientificCalculator {
  int a;
  int b;
  
public:
  void get_data_scientific(){
    cout << "Enter the value of a " << endl;
    cin >> a;
    cout << "Enter the value of b" << endl;
    cin >> b;
  }

  void performOpsScientific(){
    cout << "The value of cos(a) = " << cos(a) << endl;
    cout << "The value of sin(a) = " << sin(a) << endl;
    cout << "The value of exp(a) = " << exp(a) << endl;
    cout << "The value of tan(a) = " << tan(a) << endl;
  }
  
};


class HybridCalculator: public SimpleCalculator, public ScientificCalculator{

};


int main(){
  // SimpleCalculator calc;
  // calc.get_data_simple();
  // calc.performOpsSimple();

  HybridCalculator hcalc;
  hcalc.get_data_simple();
  hcalc.performOpsSimple();

  hcalc.get_data_scientific();
  hcalc.performOpsScientific();

  return 0;
}
