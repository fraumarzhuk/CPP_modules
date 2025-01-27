#include "Bureaucrat.hpp"



int main() {
	{
	Bureaucrat	andor("Tamas", 42);
	std::cout << andor << std::endl;

	try {
		Form	whatchamin("Whatchamean", 0, 20);
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form	france("France is the best country", 7, 65);
		std::cout << france << std::endl;
		andor.signForm(france);
		Form	germany("Germany is a nice country", 70, 2);
		std::cout << germany << std::endl;
		andor.signForm(germany);
		Form	hungary("Hungary is the best country", 42, 2);
		std::cout << hungary << std::endl;
		andor.signForm(hungary);
		andor.signForm(hungary);
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
	}
}