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
void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return "";
}