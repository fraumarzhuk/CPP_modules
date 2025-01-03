#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << PURPLE300 << "ScavTrap: "<< RESET << "default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(){
	std::cout << PURPLE300 <<"ScavTrap: "<< RESET << "destructor called" << std::endl;
}
void ScavTrap::guardGate(){
	std::cout << LIME400 << "ScavTrap is now in GateKeeper mode" << RESET << std::endl;
}