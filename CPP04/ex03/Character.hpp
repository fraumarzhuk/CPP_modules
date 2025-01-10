#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "colors.hpp"
#include <iostream>

class AMateria;
//concrete
class Character: public ICharacter
{
protected:
		std::string _name;
		AMateria *_slots[4];
public:
	Character(std::string const _name="default name");
	~Character();
	Character(const Character &other);
	Character &operator= (const Character &other);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
