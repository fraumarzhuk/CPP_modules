#include "RPN.hpp"

RPN::RPN()
{
std::cout << "RPN Constructor called" << std::endl;
}

RPN::RPN(const RPN &other)
{
	std::cout << " RPN Copy constructor called" << std::endl;
	*this = other;
}

RPN &RPN::operator = (const RPN &other)
{
	std::cout << "RPN Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << " RPN Destructor called" << std::endl;
}
