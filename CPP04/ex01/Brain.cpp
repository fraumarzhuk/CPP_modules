#include "Brain.hpp"

Brain::Brain()
{
std::cout << CYAN300 << "Brain Constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << CYAN300 << "Brain copy constructor called" << RESET << std::endl;
	*this = other;
}

Brain &Brain::operator = (const Brain &other)
{
	std::cout << CYAN300 << "Brain copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		*this->ideas = *other.ideas;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << CYAN300 << "Brain destructor called" << RESET << std::endl;
}
