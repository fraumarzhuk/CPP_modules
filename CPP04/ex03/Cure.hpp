
#ifndef CURE_HPP
#define CURE_HPP
#include "Character.hpp"
#include "colors.hpp"
#include <iostream>

//concrete
class Cure: public AMateria
{
protected:
public:
	Cure(std::string const & type="cure");
	Cure &operator = (const AMateria &other);
	Cure(const Cure &other);
	Cure* clone() const;
	void use(ICharacter& target);
	~Cure();
};

#endif
