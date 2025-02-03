#include <iostream>

#include "Intern.hpp"

int main() {
	Intern test;
	test.makeForm("shrubbery creation", "buro");
	test.makeForm("presidential pardon", "bubu");
	test.makeForm("robotomy request", "buro2");
	test.makeForm("random form", "buro2");

	Bureaucrat buro2("buro2");
	AForm *robo_form = test.makeForm("robotomy request", "buro2");
	// buro2.signForm(robo_form);
	// robo_form->execute(buro2);

}