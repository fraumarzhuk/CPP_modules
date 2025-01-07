#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include "colors.hpp"
#include <iostream>


class WrongAnimal
{
private:
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator= (const WrongAnimal &other);
	~WrongAnimal();
};

#endif