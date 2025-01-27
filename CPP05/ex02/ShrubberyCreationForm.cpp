#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(Bureaucrat &target): AForm("ShrubberyForm", 145, 137), _target(target)
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
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	//Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
}