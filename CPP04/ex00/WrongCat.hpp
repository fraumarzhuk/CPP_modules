#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include "colors.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{
private:
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator= (const WrongCat &other);
	~WrongCat();

	void makeSound() const;
};


#endif