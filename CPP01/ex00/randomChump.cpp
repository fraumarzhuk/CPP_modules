#include "Zombie.hpp"

void Zombie::randomChump(std::string name){
	this->newZombie(name);
	this->announce();
}