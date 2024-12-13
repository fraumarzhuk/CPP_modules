#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_setName(name);
	return;
}

Zombie::~Zombie(void){
	delete this;
	std::cout << this->_name << " is destroyed." << std::endl;
	return;
}

void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(){
	return (this->_name);
}
void Zombie::_setName(std::string name){
	this->_name = name;
}
