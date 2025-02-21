#include <iostream>
#include <stdlib.h>
#include "Base.hpp"
#include "Aclass.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"


int main() {
	std::srand(std::time(NULL));
	std::cout << PINK600 << "Pointers:" << RESET << std::endl;
	Base *random_class = generate();
	identify(random_class);
	Base *random_class1 = generate();
	identify(random_class1);
	Base *random_class2 = generate();
	identify(random_class2);
	Base *random_class3 = generate();
	identify(random_class3);

	std::cout << GREEN600 << "Refs:" << RESET << std::endl;
	Aclass A;
	Bclass B;
	Cclass C;

	identify(B);
	identify(A);
	identify(C);
	delete random_class;
	delete random_class1;
	delete random_class2;
	delete random_class3;


}
