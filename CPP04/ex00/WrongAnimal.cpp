#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(std::string type): _type(type)
{
std::cout << "Wrong animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Wrong animal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &other)
{
	std::cout << "Wrong animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal destructor called" << std::endl;
}
void WrongAnimal::makeSound() const 
{
	std::cout << _type << ": Wa-pa-pa-pa-pa-pa-pow!Wa-pa-pa-pa-pa-pa-pow!" << std::endl;
}