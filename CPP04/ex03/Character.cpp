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
		_name = other._name;
		delete _slots[4];
		for (int i = 0; i < 4; i++)
		{
			_slots[i] = other._slots[i];
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Unexisting Materia" << std:: endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = m;
			return ;
		}
	}
	std::cout << "Slots are full" << std::endl;
	return ;
}

void Character::unequip(int idx)
{
	//The unequip() member function must NOT delete the
	//Materia!
	_slots[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
	_slots[idx]->use(target);
}
