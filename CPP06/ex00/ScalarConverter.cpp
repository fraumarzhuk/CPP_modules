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
	if (c <= 0 || (c >= 0 && c <= 31))
		std::cout << "Char : non displayable" << std::endl;
	else
		std::cout << "Char : " << c << std::endl;
	std::cout << "Int : " << static_cast<int>(c) << std::endl;
	std::cout << "Float : " << std::fixed << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << static_cast<double>(c) << std::endl;
}

void ScalarConverter::_convert_float(std::string str)
{
	float res = std::strtof(str.c_str(), NULL);
	std::cout << "Char : " << static_cast<char>(static_cast<int>(res)) << std::endl;
	std::cout << "Int : " << static_cast<int>(res) << std::endl;
	std::cout << "Float : " << std::fixed << static_cast<float>(res) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << static_cast<double>(res) << std::endl;
	exit(0);
}

void ScalarConverter::_convert_double_and_int(std::string str)
{
	double result  = std::strtof(str.c_str(), NULL);
	if (result > INT_MIN && result < INT_MAX)
		std::cout << "Int : " << static_cast<int>(result) << std::endl;
	else
		std::cout << "Int : Impossible!" << std::endl;

	if (result >= 0 && result <= 127)
		std::cout << "Char : " << static_cast<char>(result) << std::endl;
	else
		std::cout << "Char : Impossible" << std::endl;
	std::cout << "Double : " << std::fixed << static_cast<double>(result) << std::endl;
	std::cout << "Float : " << std::fixed << static_cast<float>(result) << "f" << std::endl;
}

void ScalarConverter::convert(char *str)
{
	std::string input(str);
	std::cout.precision(2);
	int res;

	if (_is_a_string(str))
		std::cout << "Invalid input!" << std::endl, exit(1);
	if (input.length() == 1){
		if (isdigit(str[0]))
			res = atoi(str);
		else
			res = str[0];
		_convert_char(res), exit(1);
	}
	else{
		_check_number_string(str);
	}
}

//rewrite this bs: infinite loop
bool ScalarConverter::_is_repeated(std::string str, char c){
	size_t pos = 0;
	int counter = 0;
	while ((pos = str.find(c, pos)) != std::string::npos){
		counter++;
		pos++;
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


void ScalarConverter::_check_number_string(std::string str)
{
    size_t pos = 0;
    if (str.length() > 30)
        std::cout << "Invalid input" << std::endl;
    if (_is_scientific(str))
    {
        _convert_scientific(str);
        return;
    }
    // if ((((str[0] == '+') && _is_repeated(str, '+')) || (((str[0] == '-') && _is_repeated(str, '-')) && !_is_scientific(str))))
	if ((str[0] == '+' && _is_repeated(str, '+')) || (str[0] == '-' && _is_repeated(str, '-')))
        std::cout << "Invalid input1" << std::endl, exit(1);// signs not repeated
    if (!isdigit(str[0]) && (str[0] != '-' && str[0] != '+'))
        std::cout << "Invalid input2" << std::endl, exit(1); //first char is num or sign
    if ((pos = str.find('+')) != std::string::npos && pos != 0)
        std::cout << "Invalid input3" << std::endl, exit(1); // already cheked and exited on scientific
    if ((pos = str.find('-')) != std::string::npos && pos != 0)
        std::cout << "Invalid input4, pos : " << pos << std::endl, exit(1);
    if ((str.find('f') != std::string::npos || str.find('F') != std::string::npos) && str.find('.') != std::string::npos)
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

	size_t dot_pos = str.find('.');
	if ((!_is_sign(str[0]) && dot_pos != 1) || (_is_sign(str[0]) && dot_pos != 2))
		std::cout << "Invalid input5" << std::endl, exit(1);
	std::string coeff_part = str.substr(0, dot_pos);
	double coeff = ::atof(coeff_part.c_str());

	size_t pos = str.find('e');
	if (pos == std::string::npos)
		pos = str.find('E');
	if (pos == std::string::npos)
		std::cout << "Invalid input5" << std::endl, exit(1);

	std::string exp_part = str.substr(pos + 1);
	if (exp_part.length() > 3 && !_is_sign(exp_part[0]))
		std::cout << "Invalid input6" << std::endl, exit(1);
	if (_is_repeated(coeff_part, '-') || _is_repeated(coeff_part, '+') || _is_repeated(exp_part, '-') || _is_repeated(exp_part, '+'))
		std::cout << "Invalid input7" << std::endl, exit(1);
	// add check only digits in the exp part
	int exp = atoi(exp_part.c_str());
	double result = static_cast<double> (coeff * pow(10, exp));
	std::cout << "Char: Impossible! " << std::endl;
	std::cout << "Int: Impossible! " << std::endl;
	std::cout << "Double: " << std::fixed << result << std::endl;
	std::cout << "Float: " << std::fixed << static_cast<float> (result) << "f" << std::endl;
	return result;
}