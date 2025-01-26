#include "Cure.hpp"

Cure::Cure(): AMateria("Cure")
{
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "Cure Copy constructor called" << std::endl;
	*this = other;
}

Cure &Cure::operator = (const Cure &other)
{
	std::cout << "Cure Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

Cure *Cure::clone() const
{
	Cure *new_cure = new Cure();
	return new_cure;
}

void Cure::use(ICharacter& target) {
  std::cout << "Cure: * heals " << target.getName()<< "'s wounds *\n";
}

Cure::~Cure()
{
	std::cout << " Cure Destructor called" << std::endl;
}
