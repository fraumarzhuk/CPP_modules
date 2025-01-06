#ifndef DIMANOD_TRAP_HPP
#define DIAMOND_TRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string _name;
	std::string _clap_trap_name;
public:
	DiamondTrap(std::string name="default");
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();
};



#endif