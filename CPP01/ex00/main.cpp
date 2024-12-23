#include "Zombie.hpp"
#include "newZombie.hpp"
#include "colors.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

int main(){
	int amount = 0;
	std::string input;
	std::string zombie_names[5] = {"Harry", "Draco", "Pancy", "Blaise", "Hermione"};
	Zombie stack_zombies_arr[5];
	std::cout << INDIGO200 << "Allocating Zombie on stack" << RESET <<std:: endl;
	for (int i = 0; i < 5; i++){
		stack_zombies_arr[i].setName(zombie_names[i]);
		stack_zombies_arr[i].announce();
	}
	std::cout << INDIGO200 << "Allocating Zombie on heap" << RESET << std:: endl;
	while (amount == 0 || (amount < 0 || amount > 50)){
		std::cout << "How many zombies do you want to create?" << std:: endl;
		std::cin >> input;
		amount = strtol(input.c_str(), (char **) NULL, 10);
	}
	Zombie* heap_zombies[amount];
	std::cout << INDIGO200 << "Allocating Zombie on heap" << RESET <<std:: endl;
	for (int i = 0; i < amount; i++){
		heap_zombies[i] = newZombie(zombie_names[i % 5]);
		heap_zombies[i]->announce();
	}
	Zombie random_zombie;
	std::cout << INDIGO200 << "Creating random dude" << std:: endl;
	random_zombie.randomChump("Random_dude");
	for (int i = 0; i < amount; i++){
		delete heap_zombies[i];
	}
}