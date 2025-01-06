#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name){
	this->_name = name;
	this->_clap_trap_name = ClapTrap::getName() + " _clap_name";
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
	std::cout << BLUE600 << "💎 DiamondTrap: "<< RESET << "default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << BLUE600 <<"💎 DiamondTrap: "<< RESET << "destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	std::cout << BLUE600 <<"💎 DiamondTrap: "<< RESET <<  "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setHitPoints(other.getHitPoints());

	}
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << BLUE600 <<"💎 DiamondTrap: "<< RESET << "Copy constructor called" << std::endl;
	*this = other;
}
void DiamondTrap::attack(std::string target){
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI(){
	std::cout << BLUE600 << "Diamond trap names: " << RESET << this->_name + " and " + this->_clap_trap_name << std::endl;
}