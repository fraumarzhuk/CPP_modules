#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << " ScalarConverter Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &other)
{
	std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		//assign;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << " ScalarConverter Destructor called" << std::endl;
}

void ScalarConverter::convert(char *str)
{
    std::string input(str);

	//check for -inff, +inff and nanf.
	// then check if !contains nums
		//convert to string
    if (input.find('f') != std::string::npos)
        float float_conv = std::strtof(str, nullptr);
    else if (input.find('.') != std::string::npos || input.find('e') != std::string::npos)
        double float_conv = std::strtod(str, nullptr);
    else
        int int_conv = std::atoi(str);
}
