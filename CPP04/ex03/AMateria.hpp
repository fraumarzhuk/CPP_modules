#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "colors.hpp"
#include "ICharacter.hpp"

//abstract class

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria &other);
		AMateria &operator= (const AMateria &other);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};
#endif
