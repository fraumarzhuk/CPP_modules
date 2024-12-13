#include "Zombie.hpp"

Zombie *newZombie(std::string name){
	Zombie *newZombie = new Zombie(name);
	// newZombie->_setName(name);
	return (newZombie);
}
