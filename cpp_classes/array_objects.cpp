#include<iostream>
using namespace std;

class ShopItem{
    int item;
    float price;

    public:
        void setData(int id, float pr){
            item = id;
            price = pr;
        }

        void getData(){
            cout  << "The item id is " << item << endl;
            cout << "The item price is " << price << endl;
        }
};


int main(){

    int size = 3;
    ShopItem *ptr = new ShopItem[size];
    ShopItem *tempPtr = ptr;

    int i, id;
    float price;

    for(i = 0; i < size; i++){
        cout << "Enter the item id and price of item " << i + 1 << endl;
        cin >> id >> price;
        ptr -> setData(id, price);
        ptr++;
    }

    for(i = 0; i < size; i++){
        tempPtr -> getData();
        tempPtr++;
    }

    return 0;
}