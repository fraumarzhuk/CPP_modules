#include <iostream>
#include <stdlib.h>
#include "Base.hpp"
#include "Aclass.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"


int main() {
	std::cout << PINK600 << "Pointers:" << RESET << std::endl;
	Base *random_class = generate();
	identify(random_class);
	random_class = generate();
	identify(random_class);
	random_class = generate();
	identify(random_class);
	random_class = generate();
	identify(random_class);

	std::cout << GREEN600 << "Refs:" << RESET << std::endl;
	Aclass A;
	Bclass B;
	Cclass C;

	identify(A);
	identify(B);
	identify(C);


}
