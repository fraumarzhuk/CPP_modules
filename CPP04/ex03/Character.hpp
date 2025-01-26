#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "colors.hpp"
#include "MyList.hpp"

class AMateria;

class Character: public ICharacter
{
private:
	std::string _name;
	AMateria * _slots[4];
	MyList _unequipped_materias;
public:
	Character(std::string name);
	Character(const Character &other);
	Character &operator= (const Character &other);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
#endif
