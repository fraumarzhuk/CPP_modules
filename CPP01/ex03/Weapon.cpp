#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}
const std::string& Weapon::getType(){
	return this->_type;
}
void Weapon::setType(std::string type_name){
	this->_type = type_name;
}