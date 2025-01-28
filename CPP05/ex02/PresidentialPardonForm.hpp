#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class PresidentialPardonForm: public AForm
{
private:
	Bureaucrat &_target;
public:
	PresidentialPardonForm(Bureaucrat &target);
	Bureaucrat &getTarget() const;
	void action() const;
	~PresidentialPardonForm();
};
#endif
