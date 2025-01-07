#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include "colors.hpp"
#include <iostream>


class WrongAnimal
{
protected:
	std::string _type;
public:
	WrongAnimal(std::string type="Wrong animal");
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator= (const WrongAnimal &other);
	~WrongAnimal();

	void makeSound() const;
};

#endif