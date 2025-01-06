#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << PURPLE300 << "ScavTrap: "<< RESET << "default constructor called" << std::endl;
	this->setHitPoints(100); //change? to _hitpoints = 10?
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap(){
	std::cout << PURPLE300 <<"ScavTrap: "<< RESET << "destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	std::cout << CYAN300 <<"ScavTrap: "<< RESET <<  "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setHitPoints(other.getHitPoints());

	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
	std::cout << CYAN300 <<"ScavTrap: "<< RESET << "Copy constructor called" << std::endl;
	*this = other;
}

void ScavTrap::guardGate(){
	std::cout << LIME400 << "ScavTrap is now in GateKeeper mode" << RESET << std::endl;
}

void ScavTrap::attack(std::string target){
		std::cout << PURPLE300 << "ScavTrap " + this->getName() + " attacks " + target + " , causing " << this->getAttackDamage() << " points of damage!"<< RESET << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
}