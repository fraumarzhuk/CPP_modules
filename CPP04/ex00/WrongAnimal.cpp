#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
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
		//assign;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal destructor called" << std::endl;
}
