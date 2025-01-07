#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "colors.hpp"
#include <iostream>

class Animal
{
private:
protected:
	std::string _type;
public:
	Animal(std::string type="Some animal");
	Animal(const Animal &other);
	Animal &operator= (const Animal &other);
	~Animal();
	virtual void makeSound() const;

	std::string getType() const;
	void setType(const std::string &type);
};

#endif