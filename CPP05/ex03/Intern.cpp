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
	std::cout << CYAN400 << "Intern Constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << CYAN400 << " Intern Copy constructor called" << RESET << std::endl;
	*this = other;
}

Intern &Intern::operator = (const Intern &other)
{
	std::cout << "Intern Copy assignment operator called" << RESET << std::endl;
	if (this != &other){
		std::cout << CYAN400 << "Nothing to copy" << RESET << std::endl;
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << CYAN400 << " Intern Destructor called" << RESET << std::endl;
}

AForm *Intern::makeForm(std::string form_name, std::string target_name)
{
	FormTypes form_types[NUM_FORMS] = {&Intern::makeShrubbyForm, &Intern::makePresidentialForm, &Intern::makeRobotomyForm};
    std::string form_names[NUM_FORMS] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    for (int i = 0; i < NUM_FORMS; ++i)
    {
        if (form_names[i] == form_name)
        {
            std::cout << BLUE400 <<"Intern creates " << RESET << form_name << " form" <<  RESET << std::endl;
            return (this->*form_types[i])(target_name);
        }
    }
    std::cerr << RED700 <<"Error: Form not found" << RESET << std::endl;
    return NULL;
}
