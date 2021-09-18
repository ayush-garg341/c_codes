#include<iostream>
using namespace std;

class ThisPointer{
    int a;

    public:
        ThisPointer& setData(int a){
            this -> a = a;
            return *this;
        }

        void getData(){
            cout << "The value of a is " << a << endl;
        }

};


int main(){
    ThisPointer tp;
    tp.setData(5).getData();
    return 0;
}