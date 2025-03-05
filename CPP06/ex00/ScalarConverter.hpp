#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <cmath>
#include "colors.hpp"
#include <climits> 
#include <string> 

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator= (const ScalarConverter &other);

	static bool _is_repeated(std::string str, char c);
	static bool _is_a_string(std::string str);
	static void _convert_infs(std::string str);
	static void _check_number_string(std::string str);
	static double _convert_scientific(std::string str);
	static bool _is_scientific(std::string str);
	static bool _is_sign(char c);
	static void _convert_char(char c);
	static void _convert_float(std::string str);
	static void _convert_double_and_int(std::string str);
	~ScalarConverter();
public:
	static void convert(char *str);
};

#endif
