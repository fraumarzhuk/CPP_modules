#ifndef ICE_HPP
#define ICE_HPP
#include <iostream>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

//concrete class

class Ice: public AMateria
{
	protected:
		std::string _type;
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator= (const Ice &other);
		Ice* clone() const;
		void use(ICharacter& target);
		~Ice();
};
#endif
