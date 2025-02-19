#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (_target);
}

// PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other.getTarget())
// {
// 	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
// }

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}
void PresidentialPardonForm::action() const
{
	std::cout << LIME300 << _target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}