#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include "colors.hpp"
#include <iostream>

class WrongCat
{
private:
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator= (const WrongCat &other);
	~WrongCat();
};


#endif