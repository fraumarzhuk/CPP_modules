#ifndef DOG_HPP
#define DOG_HPP
#include "colors.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal
{
private:
	Brain *_brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator= (const Dog &other);
	~Dog();

	Brain *getBrain() const;
	void setBrain(const Brain &brain);
	virtual void makeSound() const;
};

#endif