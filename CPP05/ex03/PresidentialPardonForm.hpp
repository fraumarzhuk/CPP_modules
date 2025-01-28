#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string _target;
public:
	PresidentialPardonForm(const std::string &target);
	const std::string &getTarget() const;
	void action() const;
	~PresidentialPardonForm();
};
#endif
