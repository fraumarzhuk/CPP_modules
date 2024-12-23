#include "Weapon.hpp"

Weapon::Weapon(): _type("Not set") {}

Weapon::Weapon(std::string name) :_type(name){}

Weapon::~Weapon(){}

const std::string &Weapon::getType() const{
	return this->_type;
}
void Weapon::setType(std::string type_name){
	this->_type = type_name;
}