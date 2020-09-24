#include <iostream>
 
void print() // this print lives in the global namespace
{
	std::cout << " there\n";
}
 
namespace foo
{
	void print() // this print lives in the foo namespace
	{
		std::cout << "Hello";
	}
}
 
int main()
{
	foo::print(); // call foo::print()
	::print(); // call print() in global namespace (same as just calling print() in this case)
 
	return 0;
}
