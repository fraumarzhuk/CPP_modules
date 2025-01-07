#include "Dog.hpp"


Dog::Dog(): Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog 🐶";
}

Dog::Dog(const Dog &other): Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
void Dog::makeSound() const 
{
	std::cout << _type << ": *bark bark bark awoooo*" << std::endl;
}
