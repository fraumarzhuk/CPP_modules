#include "Dog.hpp"


Dog::Dog(): Animal()
{
	std::cout << AMBER500 << "Dog constructor called" << RESET << std::endl;
	_type = "Dog 🐶";
	_brain = new Brain();
}

Dog::Dog(const Dog &other): Animal()
{
	std::cout << AMBER500 <<  "Dog copy constructor called" << RESET << std::endl;
	*this = other;
}

Dog &Dog::operator = (const Dog &other)
{
	std::cout << AMBER500 << "Dog copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << AMBER500 << "Dog destructor called" << RESET << std::endl;
}
void Dog::makeSound() const 
{
	std::cout << AMBER500 <<  _type << ORANGE400 <<": *bark bark bark awoooo*" << RESET << std::endl;
}
