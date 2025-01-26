#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

//concrete class

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator= (const Ice &other);
		AMateria* clone() const;
		void use(ICharacter& target);
		~Ice();
};
#endif
