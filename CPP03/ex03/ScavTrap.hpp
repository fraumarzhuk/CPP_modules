#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "colors.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string name = "default");
		void guardGate();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void attack(std::string target);
};

#endif