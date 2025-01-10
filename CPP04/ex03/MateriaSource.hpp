#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include "AMateria.hpp"
#include "colors.hpp"
#include <iostream>

class AMateria;
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
protected:
	AMateria *slots[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator= (const MateriaSource &other);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif
