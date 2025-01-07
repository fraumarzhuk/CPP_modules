#include "WrongCat.hpp"


WrongCat::WrongCat(): WrongAnimal()
{
	_type = "Wrong Cat";
	std::cout << "Wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal()
{
	std::cout << "Wrong cat copy constructor called" << std::endl;
	*this = other;
}

WrongCat &WrongCat::operator = (const WrongCat &other)
{
	std::cout << "Wrong cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong cat destructor called" << std::endl;
}
void WrongCat::makeSound() const 
{
	std::cout << _type << ": meow meow bark meow" << std::endl;
}
