#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat &target): AForm("ShrubberyForm", 25, 5), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	std::cout << " ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = &other;
}

// ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
// {
// 	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
// 	if (this != &other)
// 			std::cout << PINK300 << "Cannot assign the AForm sry" <<  RESET << std::endl;
// 	return (*this);
// }

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << " ShrubberyCreationForm Destructor called" << std::endl;
}
