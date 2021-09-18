#include<iostream>
using namespace std;


class Base{
    public:
        int var_base;
        void display(){
            cout << "The value of base class variable var_base is " << var_base << endl;
        }
};


class Derived : public Base{
    public:
        int var_derived;
        void display(){
            cout << "The value of base class variable var_base is " << var_base << endl;
            cout << "The value of derived class variable var_derived is " << var_derived << endl;
        }

};


int main(){
    Base * base_class_ptr;
    Base obj_base;

    Derived obj_derived;
    base_class_ptr = &obj_derived; // pointing base class pointer to derived class

    base_class_ptr->var_base = 34;
    base_class_ptr->display(); // base class display

    base_class_ptr->var_base = 3400;
    base_class_ptr->display();

    Derived * derived_class_ptr;
    derived_class_ptr = &obj_derived;
    derived_class_ptr->var_base = 1000;
    derived_class_ptr->var_derived = 2000;
    derived_class_ptr->display(); // derived class display

    return 0;
}