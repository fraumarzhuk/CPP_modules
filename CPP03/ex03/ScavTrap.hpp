#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "colors.hpp"
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap{
	protected:
		static const int _hp = 100;
		static const int _ep = 50;
		static const int _atk = 20;
	public:
		ScavTrap(std::string name = "default");
		void guardGate();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();
		void attack(const std::string &target);
};

#endif