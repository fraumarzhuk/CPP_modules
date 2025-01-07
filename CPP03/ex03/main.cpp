#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// ClapTrap clap("Clappy");
	// ScavTrap clap2("Cloppy");

	// clap.attack("Patrik");
	// // clap.takeDamage(10);
	// // clap.beRepaired(5); 

	// clap2.attack("Bob");
	// clap2.takeDamage(10);
	// clap2.beRepaired(5);
	std::cout << BG_EMERALD400 PINK800 << "CREATING DIAMOND TRAP" << RESET <<std::endl;
	DiamondTrap john("John");
	std::cout << "Damage Points: " << john.getAttackDamage() << std::endl;
	//john.attack("Target");
	std::cout << "HitPoints: " << john.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << john.getEnergyPoints() << std::endl;
	john.attack("an object");
	john.whoAmI();
	// std::cout << "HitPoints: " << john.getHitPoints() << std::endl;
	// std::cout << "EnergyPoints: " << john.getEnergyPoints() << std::endl;
	// john.beRepaired(3);
	// std::cout << "EnergyPoints: " << john.getEnergyPoints() << std::endl;
}