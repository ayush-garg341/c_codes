#include <iostream>
#include <string>
using namespace std;

class Date {
  int day;
  int month;
  int year;

  public:
  // Default constructor is created inside public 
  Date(){
    // We must define the default values for day, month, and year
    day = 0;
    month = 0;
    year = 0;
  }

  // A simple print function
  void printDate(){ 
    cout << "Date: " << day << "/" << month << "/" << year << endl;
  }
};

int main(){
  // Call the Date constructor to create its object;
  
  Date d; // Object created with default values!
  d.printDate();
}




// The default constructor does not need to be explicitly defined. Even if we don’t create it, the C++ compiler will call a default constructor and set data members to some junk values.

// Constructor is a special member function with the same name as of the class. It is used to initialize the objects of its class.

// It is automatically invoked.

// Do not have return types.

// We cannot refer to their address.
