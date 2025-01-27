#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	Bureaucrat &_target;
public:
	ShrubberyCreationForm(Bureaucrat &target);
	Bureaucrat &getTarget() const;
	void execute(const Bureaucrat &executor) const;
	~ShrubberyCreationForm();
};
#endif
