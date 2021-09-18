#include<iostream>
using namespace std;


class Base{
    public:
        int var_base = 1;
        virtual void display(){
            cout << "1. The value of base class variable var_base is " << var_base << endl;
        }
};


class Derived : public Base{
    public:
        int var_derived = 2;
        void display(){
            cout << "2. The value of base class variable var_base is " << var_base << endl;
            cout << "2. The value of derived class variable var_derived is " << var_derived << endl;
        }

};


int main(){
    Base * base_class_ptr;

    Derived obj_derived;
    base_class_ptr = &obj_derived; // pointing base class pointer to derived class, but by using virtual keyword in base class
    // fn. we are able to execute the derived class display rather than base class display.
    base_class_ptr -> display();

    return 0;
}