#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("Clappy");
	ClapTrap clap2("Cloppy");

	clap.attack("Patrik");
	clap.takeDamage(10);
	clap.beRepaired(5); 

	clap2.attack("Bob");
	clap2.takeDamage(10);
	clap2.beRepaired(5);
	std::cout << BG_EMERALD400 PINK800 << "CREATING FRAGTRAP" << RESET <<std::endl;
	FragTrap john("John");
	std::cout << "HitPoints: " << john.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << john.getEnergyPoints() << std::endl;
	john.attack("an object");
	std::cout << "HitPoints: " << john.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << john.getEnergyPoints() << std::endl;
	john.beRepaired(3);
	std::cout << "EnergyPoints: " << john.getEnergyPoints() << std::endl;
	john.highFivesGuys();
}