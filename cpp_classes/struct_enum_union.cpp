
#include<iostream>
using namespace std;

typedef struct employee{

    int eid;
    char favChar;
    float salary;

} ep;


union money{
    int rice;
    char car;
    float pounds;
};

// in union memory is shared among different variables...

int main(){

    ep ayush;
    ayush.eid = 1;
    ayush.favChar = 'a';
    ayush.salary = 100000.00;


    union money m1;
    m1.rice = 4;
    // m1.car = 'c'; observe the behavior here after un-commenting
    cout << m1.rice << endl;

    enum Meal {breakfast, lunch, dinner}; // {0, 1, 2}
    Meal m = lunch;
    cout << m << endl;
    cout << (m==2) << endl; // false

    return 0;
}