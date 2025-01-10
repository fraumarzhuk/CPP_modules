#include "Cure.hpp"

Cure::Cure(std::string const & type): AMateria(type)
{
	this->_type = "cure";
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &other): AMateria(other._type)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure &Cure::operator =(const AMateria &other) // keep Cure?
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure *Cure::clone() const
{
	Cure *cure_clone = new Cure("cure");
	return (cure_clone);
	//allocated on heap, delete later
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}