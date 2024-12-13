#include "Zombie.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

int main(){
	int amount = 0;
	std::string zombie_names[5] = {"Harry", "Draco", "Pancy", "Blaise", "Hermione"};
	std::cout << INDIGO200 << "Allocating Zombie on stack" << std:: endl;
	Zombie stack_zombie("Stackie");
	stack_zombie.announce();
	std::cout << INDIGO200 << "Allocating Zombie on heap" << RESET << std:: endl;
	std::cout << "How many zombies do you want to create?" << std:: endl;
	if (!std::getline(std::cin, amount))
		exit(1);
	// amount = strtol(amount.c_str(), (char **) NULL, 10);
	// for (int i = 0; i < 5, i++){
	// 	Zombie::newZombie(zombie_names[i]);
	// }

}