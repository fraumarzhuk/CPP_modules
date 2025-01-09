#include "AMateria.hpp"


AMateria::AMateria(std::string const & type)
{
std::cout << "Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator = (const AMateria &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "Destructor called" << std::endl;
}
