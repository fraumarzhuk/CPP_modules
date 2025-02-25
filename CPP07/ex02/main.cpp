#include "Array.hpp"

int main() {
	Array<int>  *a = new Array<int>();	
	std::cout << a << std::endl;
	// Array<int>  *b = new Array<int>(3);
	// (*b)[1] = 42;
	// // int test = static_cast<int>((*b)[1]);
	// std::cout << "Value of b[1]: " << (*b)[1] << std::endl;
	delete a;
	return 0;
}