#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string _target;
	mutable bool _robotomize;
public:
	RobotomyRequestForm(const std::string &target);
	const std::string &getTarget() const;
	void action() const;
	~RobotomyRequestForm();
};
#endif
