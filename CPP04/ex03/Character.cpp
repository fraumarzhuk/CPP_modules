#include "Character.hpp"


Character::Character()
{
std::cout << "Constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Character &Character::operator = (const Character &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Destructor called" << std::endl;
}
