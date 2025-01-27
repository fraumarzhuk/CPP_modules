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
		Form	france("France is the best country", 70, 65);
		std::cout << france << std::endl;
		andor.signForm(france);
		Form	germany("Germany is the best country", 7, 2); //couldnt sign.WHY
		std::cout << germany << std::endl;
		andor.signForm(germany);
		Form	hungary("Hungary is the best country", 42, 2);
		std::cout << hungary << std::endl;
		andor.signForm(hungary);
		andor.signForm(hungary); // doesnt catch the error WHY
	}
	catch ( std::exception& e ) {
		std::cerr << e.what() << std::endl;
	}
	}
}