#include "Ice.hpp"

Ice::Ice(): AMateria("Ice")
{
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = other;
}

Ice &Ice::operator = (const Ice &other)
{
	std::cout << "Ice Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

Ice *Ice::clone() const
{
	Ice *new_Ice = new Ice();
	return new_Ice;
}

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName()<< " *\n";
}

Ice::~Ice()
{
	std::cout << " Ice Destructor called" << std::endl;
}
