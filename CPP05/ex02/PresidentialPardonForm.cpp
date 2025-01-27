#include "PresidentialPardonForm.hpp"

PresidentialPardon::PresidentialPardon(Bureaucrat &target): AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardon Constructor called" << std::endl;
}

Bureaucrat &PresidentialPardon::getTarget() const
{
	return (_target);
}

PresidentialPardon::PresidentialPardon(const PresidentialPardon &other): AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), _target(other.getTarget())
{
	std::cout << "PresidentialPardon Copy constructor called" << std::endl;
}

PresidentialPardon::~PresidentialPardon()
{
	std::cout << "PresidentialPardon Destructor called" << std::endl;
}
void PresidentialPardon::execute(const Bureaucrat &executor) const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}