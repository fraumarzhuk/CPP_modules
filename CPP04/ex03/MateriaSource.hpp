#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include "AMateria.hpp"
#include "colors.hpp"
#include <iostream>

//Interface
class IMateriaSource
{
	public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

//concrete
class MateriaSource: public IMateriaSource
{
public:
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif