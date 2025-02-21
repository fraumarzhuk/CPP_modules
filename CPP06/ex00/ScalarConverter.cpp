#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cstring>
#include <limits>
#include <string.h> 
#include <float.h> 

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	std::cout << " ScalarConverter Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator = (const ScalarConverter &other) {
	std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {
	std::cout << " ScalarConverter Destructor called" << std::endl;
}

void ScalarConverter::_convert_char(char c) {
	if (c <= 0 || (c >= 0 && c <= 31))
		std::cout << "Char : non displayable" << std::endl;
	else
		std::cout << "Char : " << c << std::endl;
	std::cout << "Int : " << static_cast<int>(c) << std::endl;
	std::cout << "Float : " << std::fixed << static_cast<float>(c) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << static_cast<double>(c) << std::endl;
}

void ScalarConverter::_convert_float(std::string str) {
	float res = std::strtof(str.c_str(), NULL);
	std::cout << "Char : " << static_cast<char>(static_cast<int>(res)) << std::endl;
	std::cout << "Int : " << static_cast<int>(res) << std::endl;
	std::cout << "Float : " << std::fixed << static_cast<float>(res) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << static_cast<double>(res) << std::endl;
	exit(0);
}

void ScalarConverter::_convert_double_and_int(std::string str) {
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
	if (result < FLT_MAX)
		std::cout << "Float : " << std::fixed << static_cast<float>(result) << "f" << std::endl;
	else
		std::cout << "Float : Impossible!" << std::endl;

}

void ScalarConverter::convert(char *str)
{
	std::string input(str);
	std::cout.precision(2);
	int res;
	if (std::string(str).length() == 1 && !isdigit(str[0]))
		_convert_char(str[0]), exit(0);
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

bool ScalarConverter::_is_repeated(std::string str, char c){
	size_t pos = 0;
	int counter = 0;
	while ((pos = str.find(c, pos)) != std::string::npos){
		if ((str[pos] == '+' || str[pos] == '-') && (pos != 0 && str[pos - 1] != 'e' && str[pos -1] != 'E'))
			std::cout << "Invalid input1" << std::endl, exit(1);
		counter++;
		pos++;
	}
	return (counter > 1);
}

bool ScalarConverter::_is_a_string(std::string str){

	if (!str.compare("inf") || !str.compare("-inf") || !str.compare("nan"))
		_convert_infs(str);
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

void ScalarConverter::_convert_infs(std::string str) {

	double res = std::numeric_limits<double>::infinity();
	if (str[0] == '-')
		res = res * -1;
	else if (str == "nan")
		res = NAN;
	std::cout << "Char : Impossible!" << std::endl;
	std::cout << "Int : Impossible" << std::endl;
	std::cout << "Float : " << std::fixed << static_cast<float>(res) << "f" << std::endl;
	std::cout << "Double : " << std::fixed << static_cast<double>(res) << std::endl;
	exit(0);
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
	if ((str[0] == '+' && _is_repeated(str, '+')) || (str[0] == '-' && _is_repeated(str, '-')))
	{
		_convert_double_and_int(str);
		return ;
	}
	if (!isdigit(str[0]) && (str[0] != '-' && str[0] != '+'))
		std::cout << "Invalid input2" << std::endl, exit(1); 
	if ((pos = str.find('+')) != std::string::npos && pos != 0 && str.find('e') !=std::string::npos)
		std::cout << "Invalid input3" << std::endl, exit(1);
	else if (((pos = str.find('-')) != std::string::npos && pos != 0 && str[pos - 1] != 'e' && str[pos - 1] != 'E'))
		std::cout << "Invalid input4, pos : " << pos << std::endl, exit(1);
	if ((str.find('f') != std::string::npos || str.find('F') != std::string::npos) && str.find('.') != std::string::npos)
		_convert_float(str);
	if (((pos = str.find('e')) != std::string::npos && pos == str.length() - 1))
		std::cout << "Invalid input!" << std::endl, exit(1);
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
	if (!str[dot_pos - 1] || !str[dot_pos + 1])
		std::cout << "Invalid input5" << std::endl, exit(1);
	size_t pos = str.find('e');
	if (pos == std::string::npos)
		pos = str.find('E');
	if (pos == std::string::npos)
		std::cout << "Invalid input5" << std::endl, exit(1);
	std::string coeff_part = str.substr(0, pos);
	float coeff = ::atof(coeff_part.c_str());
	std::string exp_part = str.substr(pos + 1);
	if (exp_part.length() > 3 && !_is_sign(exp_part[0]))
		std::cout << "Invalid input6" << std::endl, exit(1);
	if (_is_repeated(coeff_part, '-') || _is_repeated(coeff_part, '+') || _is_repeated(exp_part, '-') || _is_repeated(exp_part, '+'))
		std::cout << "Invalid input7" << std::endl, exit(1);
	for (size_t i = 1; i < exp_part.length(); i++)
	{
		if (!isdigit(exp_part[i]))
			std::cout << "Invalid input8" << std::endl, exit(1);
	}
	double exp = atof(exp_part.c_str());
	std::cout << "Coeff: " << coeff << " Exp part: " << exp_part << std::endl;
	double result = static_cast<double> (coeff * pow(10, exp));
	std::cout << "Char: Impossible! " << std::endl;
	std::cout << "Int: Impossible! " << std::endl;
	std::cout << "Double: " << std::fixed << result << std::endl;
	std::cout << "Float: " << std::fixed << static_cast<float> (result) << "f" << std::endl;
	return result;
}

/* 
c2r8s4% ./casts -245e-3
Int : 0
Char : Impossible
Double : -0.25
Float : -0.25f
atof: -0.24
 */