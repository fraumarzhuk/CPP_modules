#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Amateria.hpp"
#include "colors.hpp"
#include <iostream>

//concrete

class Character
{
public:
	~Character() {}
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, Character& target);
};

#endif