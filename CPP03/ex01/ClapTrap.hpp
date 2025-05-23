#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include "colors.hpp"
#include <iostream>

class ClapTrap{
protected:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public:
	ClapTrap(std::string name="default");
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setHitPoints(int num);
	void setEnergyPoints(int num);
	void setAttackDamage(int num);
	void setName(const std::string name);

	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
	const std::string &getName() const;

	~ClapTrap();
};

#endif