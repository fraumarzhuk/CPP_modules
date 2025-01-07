#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << PINK200 << "FragTrap: "<< RESET << "default constructor called" << std::endl;
	this->_hitPoints = _hp;
	this->_energyPoints = _ep;
	this->_attackDamage = _atk;
}

FragTrap::~FragTrap(){
	std::cout << PINK200 <<"FragTrap: "<< RESET << "destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	std::cout << PINK200 <<"FragTrap: "<< RESET <<  "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;

	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {
	std::cout << PINK200 <<"FragTrap: "<< RESET << "Copy constructor called" << std::endl;
	*this = other;
}

void FragTrap::highFivesGuys(void){
	std::cout << PINK200 <<"FragTrap: "<< RESET << "👋🏻🙏🏻👋🏻" << std::endl;
}