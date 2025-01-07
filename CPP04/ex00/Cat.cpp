#include "Cat.hpp"


Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat 🐱";
}

Cat::Cat(const Cat &other): Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << _type << ": *mew meooow meow MEAUAW!!! miu.*" << std::endl;
}
