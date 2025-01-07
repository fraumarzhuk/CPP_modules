#include "Animal.hpp"


Animal::Animal()
{
std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Animal &Animal::operator = (const Animal &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Destructor called" << std::endl;
}

void Animal::makeSound() const 
{
	std::cout << _type << ": *makes a random animal sound*" << std::endl;
}
