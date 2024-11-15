#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return;
}

Zombie::~Zombie(void)
{
	return;
}

void Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}