#ifndef ICE_HPP
#define ICE_HPP
#include "Character.hpp"
#include "colors.hpp"
#include <iostream>

//concrete

class Ice: public AMateria
{
protected:
public:
	Ice(std::string const & type="ice");
	Ice &operator = (const AMateria &other);
	Ice* clone() const;
	void use(ICharacter& target);
	~Ice();
};

#endif