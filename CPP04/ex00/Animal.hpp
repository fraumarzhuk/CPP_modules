#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "colors.hpp"
#include <iostream>

class Animal
{
private:
protected:
	std::string _type = "Some animal";
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator= (const Animal &other);
	~Animal();
	virtual void makeSound() const;
};
#endif