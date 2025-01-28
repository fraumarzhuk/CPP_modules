#include "Intern.hpp"

AForm *Intern::makeShrubbyForm(const std::string &target_name)
{
	ShrubberyCreationForm *new_form = new ShrubberyCreationForm(target_name);
	return new_form;
}

AForm *Intern::makePresidentialForm(const std::string &target_name)
{
	PresidentialPardonForm *new_form = new PresidentialPardonForm(target_name);
	return new_form;
}

AForm *Intern::makeRobotomyForm(const std::string &target_name)
{
	RobotomyRequestForm *new_form = new RobotomyRequestForm(target_name);
	return new_form;
}

Intern::Intern()
{
	// form_types = {&Intern::makeShrubbyForm, &Intern::makePresidentialForm, &Intern::makeRobotomyForm};
	// form_names = {"shrubbery creation", "presidential pardon", "robotomy request"};
	std::cout << "Intern Constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << " Intern Copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator = (const Intern &other)
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < NUM_FORMS; ++i)
        {
            form_types[i] = other.form_types[i];
            form_names[i] = other.form_names[i];
        }
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << " Intern Destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string form_name, std::string target_name)
{
    for (int i = 0; i < NUM_FORMS; ++i)
    {
        if (form_names[i] == target_name)
        {
            std::cout << "Intern creates " << target_name << std::endl;
            return (this->*form_types[i])(target_name);
        }
    }
    std::cerr << "Error: Form not found" << std::endl;
    return nullptr;
}
