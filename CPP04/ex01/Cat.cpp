#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << VIOLET500 << "Cat constructor called" << RESET << std::endl;
	_type = "Cat 🐱";
	_brain = new Brain();
}

Cat::Cat(const Cat &other): Animal()
{
	std::cout << VIOLET500 <<  "Cat copy constructor called" << RESET << std::endl;
	_type = other._type;
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator = (const Cat &other)
{
	std::cout << VIOLET500 << "Cat copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		_type = other._type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << VIOLET500 << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const 
{
	std::cout << VIOLET500 << _type << FUCHSIA400 <<": *mew meooow meow MEAUAW!!! miu.*" << RESET << std::endl;
}

Brain* Cat::getBrain() const
{
	return _brain;
}

void Cat::setBrain(const Brain &brain)
{
	*_brain = brain;
}