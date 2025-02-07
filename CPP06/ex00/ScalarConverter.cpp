#include "ScalarConverter.hpp"
#include <cstdlib> // for atof
#include <cstring> // for strtof

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

void ScalarConverter::_convert_char(char c){
	std::cout << "Char : " << c << std::endl;
}

void ScalarConverter::_convert_float(std::string str)
{
	std::cout << "float : " << static_cast<float>(std::strtof(str.c_str(), NULL)) << std::endl;
	exit(0);
}

void ScalarConverter::_convert_double_and_int(std::string str)
{
	double result  = std::strtof(str.c_str(), NULL);
	if (result > INT_MIN && result < INT_MAX)
		std::cout << "int : " << static_cast<int>(result) << std::endl;
	else
		std::cout << "double : " << static_cast<double>(result) << std::endl;
}

void ScalarConverter::convert(char *str)
{
	std::string input(str);
	if (input.length() == 1)
		_convert_char(str[0]), exit(1);
	if (_is_a_string(str))
		std::cout << input << std::endl;
	else{
		_check_number_string(str);
		// std::cout << "To be converted" << std::endl;
	}
}

//rewrite this bs: infinite loop
bool ScalarConverter::_is_repeated(std::string str, char c){
	int pos = 0;
	int found = 0;
	int counter = 0;
	while ((pos = str.find(c, found) != std::string::npos) && pos != found){
		found = pos;
		counter++;
	}
	return (counter > 1);
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

// double sc = 4.44e-400;

void ScalarConverter::_check_number_string(std::string str)
{
	int pos = 0;
	if (str.length() > 30)
		std::cout << "Invalid input" << std::endl;
	if (_is_scientific(str))
	{
		_convert_scientific(str);
		return;
	}
	if (((str[0] == '+') && _is_repeated(str, '+')) || (((str[0] == '-') && _is_repeated(str, '-') && !_is_scientific(str))))
		std::cout << "Invalid input1" << std::endl, exit(1);// signs not repeated
	if (!isdigit(str[0]) && (str[0] != '-' && str[0] != '+'))
		std::cout << "Invalid input2" << std::endl, exit(1); //first char is num or sign
	if ((pos = str.find(str, '+') != std::string::npos) && pos != 0)
		std::cout << "Invalid input3" << std::endl, exit(1); // already cheked and exited on scientific
	if ((pos = str.find(str, '-') != std::string::npos) && pos != 0)
		std::cout << "Invalid input4" << std::endl, exit(1);
	if ((str.find(str, 'f') != std::string::npos || str.find(str, 'F') != std::string::npos) && str.find(str, '.') != std::string::npos)
		_convert_float(str);
	_convert_double_and_int(str);
}

bool ScalarConverter::_is_sign(char c){
	return (c == '+' || c == '-');
}

bool ScalarConverter::_is_scientific(std::string str){
	return ((str.find('e') != std::string::npos || str.find('E') != std::string::npos) && str.find('.') != std::string::npos);
}

double ScalarConverter::_convert_scientific(std::string str){

	int pos = str.find(str, '.');
	std::string coef_part = str.substr(0, pos + 1);
	if (coef_part.length() != 1 && !_is_sign(coef_part[0]))
		std::cout << "Invalid input5" << std::endl;
	//-< checked first digit
	pos = str.find(str, 'e');
	double coeff = ::atof(coef_part.c_str());
	// -< coeff part calculated
	std::string exp_part = str.substr(pos + 1, str.length() + 1);
	if (exp_part.length() > 3 && !_is_sign(exp_part[0]))
		std::cout << "Invalid input6" << std::endl;
	int exp = ::atof(exp_part.c_str());
	// -< exp part calculated
	double result = static_cast<double>(pow(coeff, exp));
	std::cout << "Double: " << result << std::endl;
	return (result);
}
