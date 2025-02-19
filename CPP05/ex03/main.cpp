#include <iostream>

#include "Intern.hpp"

int main() {
	Intern test;
	AForm *shrubby = test.makeForm("shrubbery creation", "buro");
	AForm *presidential = test.makeForm("presidential pardon", "bubu");
	AForm *robotomy = test.makeForm("robotomy request", "buro2");
	AForm *random = test.makeForm("random form", "buro2");

	Bureaucrat buro1("buro", 2);
	try {
		robotomy->beSigned(buro1);
		robotomy->execute(buro1);
	}
	catch (std::exception &e) {
		std::cerr<< e.what() << std::endl;
	}

	Bureaucrat buro2("buro", 150);
	try {
		presidential->beSigned(buro2);
		presidential->execute(buro2);
	}
	catch (std::exception &e) {
		std::cerr<< e.what() << std::endl;
	}
	delete shrubby;
	delete presidential;
	delete robotomy;
	delete random;

}