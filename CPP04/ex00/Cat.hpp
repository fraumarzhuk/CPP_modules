#ifndef CAT_HPP
#define CAT_HPP
#include "colors.hpp"
#include "Animal.hpp"
#include <iostream>

class Cat: public Animal
{
private:
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator= (const Cat &other);
	~Cat();
	
	virtual void makeSound() const;
};

#endif