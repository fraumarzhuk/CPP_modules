#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "colors.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

//concrete class

class Cure: public AMateria
{
	protected:
		std::string _type;
	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator= (const Cure &other);
		Cure* clone() const;
		void use(ICharacter& target);
		~Cure();
};
#endif
