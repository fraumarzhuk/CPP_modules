#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "colors.hpp"
#include <iostream>

class Animal
{
private:
protected:
	std::string _type;
	Animal(std::string type="Some animal");
public:
	Animal(const Animal &other);
	Animal &operator= (const Animal &other);
	virtual ~Animal() = 0;
	virtual void makeSound() const = 0;

	std::string getType() const;
	void setType(const std::string &type);
};

#endif