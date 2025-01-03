#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	std::cout << BG_EMERALD400  << "CREATING A ROBOT SCAVTRAP" << RESET <<std::endl;
	ScavTrap robot("Roboto");
	std::cout << "HitPoints: " << robot.getHitPoints() << std::endl;
	robot.beRepaired(3);

}