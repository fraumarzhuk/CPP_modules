#include "Character.hpp"



// ICharacter::ICharacter()
// {
// std::cout << "ICharacter interface constructor called" << std::endl;
// }

Character::Character(std::string const name): ICharacter(), _name(name) 
{
std::cout << " Character constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character &Character::operator = (const Character &other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}
