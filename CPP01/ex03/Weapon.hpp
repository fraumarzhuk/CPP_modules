#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include "colors.hpp"

class Weapon {
private:
	std::string _type;
public:
	Weapon();
	Weapon(std::string name);
	~Weapon();
	const std::string &getType() const;
	void setType(std::string type_name);
};


#endif