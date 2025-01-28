#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define NUM_FORMS 3

class Intern
{
private:
    typedef AForm* (Intern::*FormTypes)(const std::string &target);
	AForm *makeShrubbyForm(const std::string &target_name);
	AForm *makePresidentialForm(const std::string &target_name);
	AForm *makeRobotomyForm(const std::string &target_name);
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator= (const Intern &other);
	~Intern();

	AForm *makeForm(std::string form_name, std::string target_name);
};
#endif
