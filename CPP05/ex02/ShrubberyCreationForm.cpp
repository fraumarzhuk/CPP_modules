#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat &target): AForm("ShrubberyForm", 25, 5), _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

Bureaucrat &ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other.getTarget())
{
	std::cout << " ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << " ShrubberyCreationForm Destructor called" << std::endl;
}
