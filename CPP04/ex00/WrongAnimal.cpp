#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(std::string type): _type(type)
{
std::cout << ROSE400 <<"Wrong animal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << ROSE400 <<"Wrong animal copy constructor called" << RESET << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &other)
{
	std::cout << ROSE400 <<"Wrong animal copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << ROSE400 <<"Wrong animal destructor called" << RESET << std::endl;
}
void WrongAnimal::makeSound() const 
{
	std::cout << ROSE400 << _type << YELLOW400 <<": Wa-pa-pa-pa-pa-pa-pow!Wa-pa-pa-pa-pa-pa-pow!" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(const std::string &type)
{
	_type = type;
}