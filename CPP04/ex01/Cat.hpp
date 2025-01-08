#ifndef CAT_HPP
#define CAT_HPP
#include "colors.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator= (const Cat &other);
	~Cat();
	
	virtual void makeSound() const;
};

#endif