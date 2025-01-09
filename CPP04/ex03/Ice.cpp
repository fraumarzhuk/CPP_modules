#include "Ice.hpp"

Ice::Ice(std::string const & type): AMateria(type)
{
std::cout << "Constructor called" << std::endl;
}

Ice::Ice(const Ice &other): AMateria()
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Ice &Ice::operator = (const Ice &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Destructor called" << std::endl;
}
