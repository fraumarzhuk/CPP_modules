#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include "Character.hpp"
#include "colors.hpp"
#include <iostream>

//apparently not an interface
class ICharacter;

class AMateria
{
protected:
	std::string _type; //leave mutable?
public:
	AMateria(std::string const & type="default");
	//clone default?
	virtual AMateria &operator = (const AMateria &other) = 0;
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;
	virtual ~AMateria();
};

#endif
