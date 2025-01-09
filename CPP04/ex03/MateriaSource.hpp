#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include "Amateria.hpp"
#include "colors.hpp"
#include <iostream>

//concrete

class MateriaSource
{
public:
	~MateriaSource() {}
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif