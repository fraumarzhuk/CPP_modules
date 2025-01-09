#include "Cure.hpp"

Cure::Cure(std::string const & type)
{
std::cout << "Constructor called" << std::endl;
}

Cure::Cure(const Cure &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Cure &Cure::operator = (const Cure &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Destructor called" << std::endl;
}