#include "Character.hpp"

Character::Character(std::string name): _name(name)
{
	std::cout << "Character Constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	std::cout << " Character Copy constructor called" << std::endl;
	*this = other;
}

Character &Character::operator = (const Character &other)
{
	std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i =0; i < 4; i++){
			if (_slots[i])
			{
				delete _slots[i];
				_slots[i] = nullptr;
			}
			_slots[i] = other._slots[i]->clone();
		}

	}
	return (*this);
}

Character::~Character()
{
	for (int i =0; i < 4; i++){
		if (_slots[i])
		{
			delete _slots[i];
			_slots[i] = nullptr;
		}
	}
	std::cout << " Character Destructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_slots[idx])
		return;
	_unequipped_materias.add(_slots[idx]);
	_slots[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !_slots[idx])
		return;
	_slots[idx]->use(target);
}
