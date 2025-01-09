#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "Character.hpp"
#include "colors.hpp"
#include <iostream>

//interface

class AMateria
{
protected:
	const std::string _type;
public:
	AMateria(std::string const & type);
	AMateria &operator = (const AMateria &other);
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif