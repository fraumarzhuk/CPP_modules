#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
	Bureaucrat &_target;
public:
	ShrubberyCreationForm(Bureaucrat &target);
	Bureaucrat &getTarget() const;
	void action() const;
	~ShrubberyCreationForm();
};
#endif
