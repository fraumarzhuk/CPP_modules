#include "Animal.hpp"


Animal::Animal(std::string type): _type(type)
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

std::string Animal::getType() const
{
	return _type;
}

void Animal::setType(const std::string &type)
{
	_type = type;
}