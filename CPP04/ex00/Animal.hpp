#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "colors.hpp"
#include <iostream>

class Animal
{
private:
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator= (const Animal &other);
	~Animal();
};
#endif