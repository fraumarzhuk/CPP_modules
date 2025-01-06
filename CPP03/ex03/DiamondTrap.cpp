#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name){
	this->_name = name;
	this->_clap_trap_name = ClapTrap::getName() + " _clap_name";
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
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