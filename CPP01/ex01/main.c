#include "colors.hpp"
#include <iostream>
#include <string>
#include "Zombie.hpp"

int main(){
	std::cout << INDIGO200 << "Creating zombies with horde..." << RESET <<std:: endl;
	int n = 3;
	Zombie *horde = zombieHorde(n, "random");
	for (int i = 0; i < n; i++)
		horde[i].announce();
}