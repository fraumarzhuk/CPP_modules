#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << PURPLE300 << "ScavTrap: "<< RESET << "default constructor called" << std::endl;
	this->_hitPoints = _hp;
	this->_energyPoints = _energyPoints;
	this->_attackDamage = _atk;
}

ScavTrap::~ScavTrap(){
	std::cout << PURPLE300 <<"ScavTrap: "<< RESET << "destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	std::cout << CYAN300 <<"ScavTrap: "<< RESET <<  "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;

	}
	return (*this);
}

void ScavTrap::attack(const std::string &target){
	if (this->_energyPoints > 0){
		std::cout << PURPLE300 << "ScavTrap " + this->_name + " attacks " + target + " , causing " << this->_attackDamage << " points of damage!"<< RESET << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << RED200 << "Low on energy 🪫" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
	std::cout << CYAN300 <<"ScavTrap: "<< RESET << "Copy constructor called" << std::endl;
	*this = other;
}

void ScavTrap::guardGate(){
	std::cout << LIME400 << "ScavTrap is now in GateKeeper mode" << RESET << std::endl;
}
