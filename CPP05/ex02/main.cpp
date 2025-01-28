#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	try {
		Bureaucrat john("John", 1);
		Bureaucrat alice("Alice", 2);
		Bureaucrat bob("Bob", 140);
		ShrubberyCreationForm shrubbery(john);
		PresidentialPardonForm pardon(alice);
		RobotomyRequestForm robotomy(bob);

		std::cout << "Executing ShrubberyCreationForm:" << std::endl;
		john.signForm(shrubbery);
		john.executeForm(shrubbery);

		std::cout << "\nExecuting PresidentialPardonForm:" << std::endl;
		john.signForm(pardon);
		john.executeForm(pardon);

		std::cout << "\nExecuting RobotomyRequestForm:" << std::endl;
		john.signForm(robotomy);
		john.executeForm(robotomy);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}