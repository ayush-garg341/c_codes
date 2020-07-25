#include <iostream>

//using namespace std;

namespace A
{
  int x = 5;
  void printX()
  {
    // function statements goes here
    std::cout<<x<<std::endl;
  }
}

namespace B
{
  int x=10;
  void printX()
  {
    // function statementsgoes here
    std::cout<<x<<std::endl;
  }
}

int main()
{
   A::printX() ;
   B::printX();
   
   return 0;
}
