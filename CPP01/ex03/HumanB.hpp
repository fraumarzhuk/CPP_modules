#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <iostream>
#include "Weapon.hpp"
#include "colors.hpp"
class HumanB {

private:
	std::string _name;
	Weapon *_weapon;
public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	~HumanB();
	void attack();
};

#endif
