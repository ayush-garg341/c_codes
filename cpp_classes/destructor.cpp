// A destructor is the opposite of a constructor. It is called when the object of a class is no longer in use. The object is destroyed and the memory it occupied is now free for future use.


#include <iostream>
#include <string>
using namespace std;

class Date {
  int day;
  int month;
  int year;

  public:
  // Default constructor
  Date(){
    // We must define the default values for day, month, and year
    day = 0;
    month = 0;
    year = 0;
  }
  
  // Parameterized constructor
  Date(int d, int m, int y){
    // The arguments are used as values
    day = d;
    month = m;
    year = y;
  }

  // A simple print function
  void printDate(){ 
    cout << "Date: " << day << "/" << month << "/" << year << endl;
  }
  
  ~Date(){
    cout << "Deleting date object" << endl;
  }
};

int main(){  
  Date d(1, 8, 2018); 
  d.printDate();
}
  
