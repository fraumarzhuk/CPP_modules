#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("First");
	ClapTrap clap2("Second");

	clap.attack("Patrik");
	clap.takeDamage(10);
	clap.beRepaired(5); 

	clap2.attack("Bob");
	clap2 = clap;
	clap2.takeDamage(10);
	clap2.beRepaired(5);
	std::cout << BG_EMERALD400  << "CREATING A ROBOT SCAVTRAP" << RESET <<std::endl;
	ScavTrap robot("Roboto");
	std::cout << "HitPoints: " << robot.getHitPoints() << std::endl;
	std::cout << "EnergyPoints: " << robot.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage: " << robot.getAttackDamage() << std::endl;
	robot.beRepaired(3);
	std::cout << "HitPoints: " << robot.getHitPoints() << std::endl;
	robot.takeDamage(20);
	robot.takeDamage(100);
	robot.takeDamage(3);	
	robot.guardGate();
}