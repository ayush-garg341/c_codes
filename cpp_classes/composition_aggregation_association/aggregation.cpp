// In aggregation, the lifetime of the owned object does not depend on the lifetime of the owner.

// The owner object could get deleted but the owned object can continue to exist in the program. In composition, the parent contains a child object. This bounds the child to its parent. In aggregation, the parent only contains a reference to the child, which removes the child’s dependency.

// Let’s take the example of people and their country of origin. Each person is associated with a country, but the country can exist without that person:

#include <iostream>
#include <string>
using namespace std;

class Country{
  string name;
  int population;

  public:
  Country(string n, int p){
    name = n;
    population = p;
  }
  string getName(){
    return name;
  }
};

class Person {
  string name;
  Country* country; // A pointer to a Country object

  public: 
  Person(string n, Country* c){
    name = n;
    country = c;
  }

  string printDetails(){
    cout << "Name: " << name << endl;
    cout << "Country: " << country->getName() << endl;
  }
};

int main() {
  Country* country = new Country("Utopia", 1);
  {
    Person user("Darth Vader", country);
    user.printDetails();
  }
  // The user object's lifetime is over

  cout << country->getName() << endl; // The country object still exists!
}
