#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class PresidentialPardon: public AForm
{
private:
	Bureaucrat &_target;
public:
	PresidentialPardon(Bureaucrat &target);
	Bureaucrat &getTarget() const;
	void execute(const Bureaucrat &executor) const;
	~PresidentialPardon();
};
#endif
