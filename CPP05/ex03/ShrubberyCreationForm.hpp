#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include "AForm.hpp"
#include "colors.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(const std::string &target);
	const std::string &getTarget() const;
	void action() const;
	~ShrubberyCreationForm();
};
#endif
