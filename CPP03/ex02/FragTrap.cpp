#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << PINK200 << "FragTrap: "<< RESET << "default constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap(){
	std::cout << PINK200 <<"FragTrap: "<< RESET << "destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	std::cout << PINK200 <<"FragTrap: "<< RESET <<  "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setHitPoints(other.getHitPoints());

	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap &other){
	std::cout << PINK200 <<"FragTrap: "<< RESET << "Copy constructor called" << std::endl;
	*this = other;
}

void FragTrap::highFivesGuys(void){
	std::cout << PINK200 <<"FragTrap: "<< RESET << "👋🏻🙏🏻👋🏻" << std::endl;
}