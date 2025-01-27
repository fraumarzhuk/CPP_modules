#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class RobotomyRequestForm: public AForm
{
private:
	Bureaucrat &_target;
public:
	RobotomyRequestForm(Bureaucrat &target);
	Bureaucrat &getTarget() const;
	//override execute
	~RobotomyRequestForm();
};
#endif
