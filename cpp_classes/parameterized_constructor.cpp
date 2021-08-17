#include <iostream>
#include <string>
using namespace std;

class Date {
  int day;
  int month;
  int year;
  int weekday;

  public:
  // Default constructor
  Date(){
    // We must define the default values for day, month, and year
    day = 0;
    month = 0;
    year = 0;
  }
  
  // Parameterized constructor and also with defualt arguments
  Date(int d, int m, int y = 2021){
    // The arguments are used as values
    day = d;
    month = m;
    year = y;
  }

  // Constructor overloading. There can be multiple constructor inside the same class.
  
  Date(int d, int m){
    day = d;
    month = m;
    year = 2021;
  }


  // A simple print function
  void printDate(){ 
    cout << "Date: " << day << "/" << month << "/" << year << endl;
  }
};

int main(){
  // Call the Date constructor to create its object;
  
  Date d(1, 8, 2018); // Object created with specified values!
  d.printDate();
}
  
// Implicit Call
// Date d(1, 8, 2010);


// Explicit Call
// Date d = Date(1, 8, 2010);

