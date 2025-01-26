#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice Copy constructor called" << std::endl;
}

Ice &Ice::operator = (const Ice &other)
{
	std::cout << "Ice Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
		*this = other;
	}
	return (*this);
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
  std::cout <<  CYAN900 << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << " Ice Destructor called" << std::endl;
}
