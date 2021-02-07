// A pure virtual function is one with the expression =0 added to the declaration.

// Once you’ve placed a pure virtual function in the base class, you must override it in all the derived classes from which you want to instantiate objects. If a class doesn’t override the pure virtual function, it becomes an abstract class itself, and you can’t instantiate objects from it.

// We can't make an object of pure virtual class.

#include <iostream>
using namespace std;

// A simple Shape interface which provides a method to get the Shape's area
class Shape {
  public:
  virtual float getArea() = 0;
};
// A Rectangle is a Shape with a specific width and height
class Rectangle : public Shape {   // derived form Shape class
  private:
  float width;
  float height;

  public:
  Rectangle(float wid, float heigh) {
    width = wid;
    height = heigh;
  }
  float getArea(){
    return width * height; 
  }
};

// A Circle is a Shape with a specific radius
class Circle : public Shape {
  private:
  float radius;

  public:
  Circle(float rad){
    radius = rad; 
  }
  float getArea(){
    return 3.14159f * radius * radius; 
  }
};

// A Square is a Shape with a specific length
class Square : public Shape {
  private:
  float length;

  public:
  Square(float len){
    length = len;
  }
  float getArea(){
    return length * length; 
  }
};

int main() {
  Shape * shape[3];   // making reference of all the deerived classes

  Rectangle r(2, 6);    // Creating Rectangle object
  shape[0] = &r;   // Referencing Shape class to Rectangle object
  
  Circle c(5);    // Creating Circle object
  shape[1] = &c;   // Referencing Shape class to Circle object

  Square s(10);   // Creating Square object
  shape[2] = &s;     // Referencing Shape class to Circle object

  for(int i=0; i<3; i++)
    cout << shape[i]->getArea() << endl;

  // Shape shp; will throw an error as pure virtual class can not instantiate objects.
}
