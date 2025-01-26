#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

//concrete class

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator= (const Cure &other);
		AMateria* clone() const;
		void use(ICharacter& target);
		~Cure();
};
#endif
