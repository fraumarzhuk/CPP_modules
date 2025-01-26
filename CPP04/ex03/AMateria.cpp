#include "AMateria.hpp"

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria Constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other): _type(other._type)
{
	std::cout << " AMateria Copy constructor called" << std::endl;
	*this = other;
}

AMateria &AMateria::operator = (const AMateria &other)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Materia is used on " << target.getName() << std::endl;
}

AMateria::~AMateria()
{
	std::cout << " AMateria Destructor called" << std::endl;
}
