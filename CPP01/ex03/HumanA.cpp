#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :_name(name), _weapon(weapon){}

HumanA::~HumanA(){}

void HumanA::attack(){
	std::cout << CYAN400 << this->_name << RESET << " attacks with their " << AMBER400 <<this->_weapon.getType() << RESET <<std::endl;
}

void HumanA::setWeapon(Weapon &weapon){
	this->_weapon = weapon;
}


