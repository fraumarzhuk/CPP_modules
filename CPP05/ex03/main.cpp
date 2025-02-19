#include <iostream>

#include "Intern.hpp"

int main() {
	Intern test;
	AForm *shrubby = test.makeForm("shrubbery creation", "buro");
	AForm *presidential = test.makeForm("presidential pardon", "bubu");
	AForm *robotomy = test.makeForm("robotomy request", "buro2");
	AForm *random = test.makeForm("random form", "buro2");

		//write a test!
	// Bureaucrat buro2("buro2");
	// AForm *robo_form = test.makeForm("robotomy request", "buro2");
	// buro2.signForm(robo_form);
	// robo_form->execute(buro2);
	delete shrubby;
	delete presidential;
	delete robotomy;
	delete random;

}