#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name){
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_energyPoints = ScavTrap::_ep;
	std::cout << BLUE600 << "💎 DiamondTrap: "<< RESET << "default constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << BLUE600 <<"💎 DiamondTrap: "<< RESET << "destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	std::cout << BLUE600 <<"💎 DiamondTrap: "<< RESET <<  "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;

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
	std::cout << BLUE600 << "Diamond trap names: " << RESET << this->_name + " and " + ClapTrap::_name << std::endl;
}