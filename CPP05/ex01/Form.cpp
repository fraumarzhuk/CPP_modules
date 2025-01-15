#include "Form.hpp"

Form::Form()
{
std::cout << "Form Constructor called" << std::endl;
}

Form::Form(const Form &other)
{
	std::cout << " Form Copy constructor called" << std::endl;
	*this = other;
}

Form &Form::operator = (const Form &other)
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << " Form Destructor called" << std::endl;
}
