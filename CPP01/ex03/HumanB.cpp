#include "HumanB.hpp"

HumanB::HumanB(std::string name) :_name(name)
{
}

HumanB::~HumanB()
{
}
void HumanB::attack(){
	std::cout << CYAN400 << this->_name << RESET << " attacks with their " << AMBER400 << this->_weapon->getType() << RESET <<std::endl;
}
void HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}
