#ifndef ICE_HPP
#define ICE_HPP
#include "Character.hpp"
#include "colors.hpp"
#include <iostream>

//concrete

class Ice
{
protected:
public:
	Ice(std::string const & type);
	
	std::string const & getType() const;
	Ice* clone() const;
	void use(ICharacter& target);
};

#endif