#include "RPN.hpp"

RPN::RPN()
{
	//std::cout << "RPN Constructor called" << std::endl;
}

RPN::RPN(const RPN &other)
{
	//std::cout << " RPN Copy constructor called" << std::endl;
	*this = other;
}

RPN &RPN::operator = (const RPN &other)
{
	//std::cout << "RPN Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}


bool RPN::is_operator(char c)
{
	return (c == PLUS || c == MINUS || c == DIVIDE || c== MULT);
}

double RPN::process_expr(std::string input)
{
	(void)input;
	return 0.0;
}

void RPN::error(std::string msg)
{
	std::cout << PINK400 << msg << RESET << std::endl;
}

bool RPN::is_correct_input(std::string input)
{
	if (input.empty())
		return false;
	for (size_t i = 0; i < input.length() - 1; i++) {
		if (!isdigit(input[i]) && !is_operator(input[i]) && !isspace(input[i])) {
			std::cout << "char " << input[i] << " .";
			RPN::error("incorrect char provided");
		}
	}
	return true;
}

RPN::~RPN()
{
	std::cout << " RPN Destructor called" << std::endl;
}
