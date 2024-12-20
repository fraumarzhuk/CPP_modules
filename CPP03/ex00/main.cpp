#include "ClapTrap.hpp"

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

}