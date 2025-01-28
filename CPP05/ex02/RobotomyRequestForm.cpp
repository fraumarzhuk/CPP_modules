#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), _target(target), _robotomize(false)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (_target);
}

// RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other.getTarget())
// {
// 	std::cout << " RobotomyRequestForm Copy constructor called" << std::endl;
// }

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << " RobotomyRequestForm Destructor called" << std::endl;
}
void RobotomyRequestForm::action() const
{
	std::cout << "** DRILLLL drilll dRiLl **" << std::endl;
	if (_robotomize)
		std::cout << _target << " has been successfuly robotomized!" << std::endl;
	else
	{
		std::cout << "robotomy failed" << std::endl;
		_robotomize = !_robotomize;
	}
	
}
