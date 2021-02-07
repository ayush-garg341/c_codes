#include "Planet.h"

Planet::Planet(double r, double m){
  radius = r;
  mass = m;
}

double Planet::getMass(){
  return mass;
}

void Planet::setMass(double m){
  mass = m;
}

double Planet::getRadius(){
  return radius;
}

void Planet::setRadius(double r){
  radius = r;
}

double Planet::calculateGravity(){
  double gravity = (G * mass)/(radius * radius);
  return gravity;
}


// All of the implementations go in this file. We simply write the class name followed by the scope resolution operator and the function name. After this comes the code for that particular function. Be sure to include header file in this file
