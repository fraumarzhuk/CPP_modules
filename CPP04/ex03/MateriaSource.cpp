#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << " MateriaSource Copy constructor called" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &other)
{
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i =0; i < 4; i++){
			if (_to_learn[i])
			{
				_to_learn[i] = nullptr;
			}
			_to_learn[i] = other._to_learn[i];
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i =0; i < 4; i++){
		if (!_to_learn[i])
			_to_learn[i] = m;
		}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i =0; i < 4; i++){
	if (_to_learn[i] && _to_learn[i]->getType() == type)
		return (_to_learn[i]->clone());
	}
	return 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << " MateriaSource Destructor called" << std::endl;
}
