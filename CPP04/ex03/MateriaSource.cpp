#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
std::cout << "Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

MateriaSource &MateriaSource::operator = (const MateriaSource &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called" << std::endl;
}
