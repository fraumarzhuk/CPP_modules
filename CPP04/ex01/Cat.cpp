#include "Cat.hpp"


Cat::Cat(): Animal()
{
	std::cout << VIOLET500 << "Cat constructor called" << RESET << std::endl;
	_type = "Cat 🐱";
}

Cat::Cat(const Cat &other): Animal()
{
	std::cout << VIOLET500 <<  "Cat copy constructor called" << RESET << std::endl;
	*this = other;
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << VIOLET500 << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << VIOLET500 << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << VIOLET500 << _type << FUCHSIA400 <<": *mew meooow meow MEAUAW!!! miu.*" << RESET << std::endl;
}
