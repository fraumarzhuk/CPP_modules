#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"

class ShrubberyCreationForm: public AForm
{
private:
public:
	ShrubberyCreationForm(Bureaucrat &target);
	//override execute
	~ShrubberyCreationForm();
};
#endif
