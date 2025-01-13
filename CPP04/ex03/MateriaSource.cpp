#include "MateriaSource.hpp"

// IMateriaSource::IMateriaSource()
// {
// std::cout << "IMateriaSource Constructor called" << std::endl;
// }


MateriaSource::MateriaSource(): IMateriaSource(), _index(0)
{
std::cout << "MateriaSource Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &other)
{
	std::cout << "MateriaSource Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia)
{
		if (!materia)
	{
		std::cout << "Unexisting Materia" << std:: endl;
		return ;
	}
	_slots[_index % 4] = materia;
	_index++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *materia;
	for (int i=0; i < 4; i++)
	{
		if (_slots[i]->getType() == type)
			materia = _slots[i]->clone();
	}
	return materia;
}
