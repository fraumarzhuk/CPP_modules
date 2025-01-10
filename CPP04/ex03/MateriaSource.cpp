#include "MateriaSource.hpp"

// IMateriaSource::IMateriaSource()
// {
// std::cout << "IMateriaSource Constructor called" << std::endl;
// }


MateriaSource::MateriaSource(): IMateriaSource()
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

void MateriaSource::learnMateria(AMateria *)
{
	// 	if (!m)
	// {
	// 	std::cout << "Unexisting Materia" << std:: endl;
	// 	return ;
	// }
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (!_slots[i])
	// 	{
	// 		_slots[i] = m;
	// 		return ;
	// 	}
	// }
	std::cout << "Slots are full" << std::endl;
	return ;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	// AMateria *materia = new AMateria(type);
	// return materia;
	std::cout << "Im done with this ex" << type << std::endl;
	return 0;
}
