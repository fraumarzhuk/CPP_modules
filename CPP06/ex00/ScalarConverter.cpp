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
    // if (input.find('f') != std::string::npos && )
	//if contains dots -> more than 1 dot -> string, less -> float or double
	//check if contains digits, one dot and f at the last letter
	if (_is_a_string(str))
		std::cout << input << std::endl;
	else{
		_check_number_string(str);
		std::cout << "To be converted" << std::endl;
	}
	// {
    //     float float_conv = std::strtof(str, NULL);

	// }
    // else if (input.find('.') != std::string::npos || input.find('e') != std::string::npos)
    //     double float_conv = std::strtod(str, NULL);
    // else
    //     int int_conv = std::atoi(str);
}


bool ScalarConverter::_is_repeated(std::string str, char c){
	int pos = 0;
	int counter = 0;
	while (pos = str.find(c, pos) != std::string::npos){
		counter++;
	}
	return (counter > 0);
}

bool ScalarConverter::_is_a_string(std::string str){

	for (size_t i = 0; i < str.length(); i++)
	{
		if ((!isdigit(str[i]) && str[i] != '.') && str[i]
			!= '-' && str[i] != '+' && str[i] != 'e' && str[i]
			!= 'E' && str[i] != 'f' && str[i] != 'F')
			return (true);
	}
	if ( _is_repeated(str, '.') || _is_repeated(str, 'e') || _is_repeated(str, 'E') || _is_repeated(str, 'f') || _is_repeated(str, 'F'))
		return true;
	return false;
}

//function that checks scientific notation
void ScalarConverter::_check_number_string(std::string str)
{
	if (str.length() > 30)
		std::cout << "Invalid input" << std::endl;
	else if (((str[0] == '+') && _is_repeated(str, '+')) || ((str[0] == '-') && _is_repeated(str, '-')))
		std::cout << "Invalid input" << std::endl;
	else if (!isdigit(str[0]) && (str[0] != '-' || str[0] != '+'))
		std::cout << "Invalid input" << std::endl;
	else if 


}

//TODO:
//1. Check if there are chars, and if yes, just output it as string
//2. Add a check just for one char

//nums:
//1.check for str[0] being a digit or sign
//2. check for repeated chars
//3. check for pos of float -- last one
//4. check for position of e (must be something after)

//1. convert to differnt types
