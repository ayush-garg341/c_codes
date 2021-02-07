// class parent

// class child : public parent

// class grandChild : public child

#include <iostream>
using namespace std;

class Vehicle {
  protected:
  string Make;
  string Color;
  int Year;
  string Model;

  public:
  Vehicle(){
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
  }

  Vehicle(string mk, string col, int yr, string mdl){
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
  }

  void print_details(){
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
    cout << "Model: " << Model << endl;
  }
};

class Cars: public Vehicle{
  string trunk_size;

  public:
  Cars(){
    trunk_size = "";
  }

  Cars(string mk, string col, int yr, string mdl, string ts)
    :Vehicle(mk, col, yr, mdl){
      trunk_size = ts;
    }

  void car_details(){
    cout << "Trunk size: " << trunk_size << endl;
  }
};

class Honda: public Cars{
  int top_speed;

  public:
  Honda(){
    top_speed = 0;
  }

  Honda(string mk, string col, int yr, string mdl, string na, int ts)
    :Cars(mk, col, yr, mdl, na){
      top_speed = ts;
    }

  void Honda_details(){
    print_details();
    car_details();
    cout << "Top speed of the car: " << top_speed << endl;
  }
};

int main(){
  Honda car("Honda", "Black", 2006, "Accord", "14.7 cubic feet", 260);
  car.Honda_details();
}
