#include<iostream>
using namespace std;

/*
Syntax for intialization list in constructor

constructor(arguemnt-list): initialization-section{
    argument + other_code;
}

*/


class Test{
    int a, b;
    public:
        // Test(int i, int j) : a(i), b(j)
        // Test(int i, int j) : a(i), b(i+j)
        // Test(int i, int j) : a(i), b(a + j)
        Test(int i, int j) : b(j), a(i+b) // will create problem here since a is declared first, but we are initializing b first.
        {
            cout << "Contructor executed" << endl;
            cout << "The value of a = " << a << endl;
            cout << "The value of b = " << b << endl;
        }

};

int main(){
    Test test(1, 2);
    return 0;
}