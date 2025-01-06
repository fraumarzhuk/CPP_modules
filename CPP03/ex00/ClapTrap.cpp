#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name),  _hitPoints(10),  _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_attackDamage = other._attackDamage;
		this->_energyPoints = other._energyPoints;
		this->_hitPoints = other._hitPoints;

	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

void ClapTrap::attack(const std::string &target){
	if (this->_energyPoints > 0)
	{
		std::cout << AMBER200 << "ClapTrap " + this->_name + " attacks " + target + " , causing " << this->_attackDamage << " points of damage!"<< RESET << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << RED200 << "Low on energy 🪫" << RESET << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (amount <= this->_hitPoints)
	{
		std::cout << PINK200 << "ClapTrap " + this->_name + " takes " << amount << " points of damage!"<< RESET << std::endl;
		this->_hitPoints -= amount;
	}
	else
		std::cout << RED200 << "No more hitpoints 💔" << RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints > 0)
	{
		std::cout << GREEN300 << "ClapTrap " + this->_name + " restores "  << amount << " points of energy! 🔋"<< RESET << std::endl;
		this->_hitPoints += amount;
	}
	else
		std::cout << RED200 << "Low on energy 🪫" << RESET << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}