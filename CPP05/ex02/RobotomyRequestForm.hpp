#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class RobotomyRequestForm: public AForm
{
private:
	Bureaucrat &_target;
	mutable bool _robotomize;
public:
	RobotomyRequestForm(Bureaucrat &target);
	Bureaucrat &getTarget() const;
	void action() const;
	~RobotomyRequestForm();
};
#endif
