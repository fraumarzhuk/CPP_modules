#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat &target): AForm("ShrubberyForm", 25, 5), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

Bureaucrat &RobotomyRequestForm::getTarget() const
{
	return (_target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other.getTarget())
{
	std::cout << " RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << " RobotomyRequestForm Destructor called" << std::endl;
}
