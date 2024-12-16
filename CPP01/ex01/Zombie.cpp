#include "Zombie.hpp"
#include "colors.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name){
	this->setName(name);
	return;
}

Zombie::~Zombie(void){
	std::cout << this->_name << " is destroyed." << std::endl;
}

void Zombie::announce(void){
	std::cout << this->_name << RED500 << ": BraiiiiiiinnnzzzZ..." << RESET <<std::endl;
}

std::string Zombie::getName(){
	return (this->_name);
}
void Zombie::setName(std::string name){
	this->_name = name;
}
