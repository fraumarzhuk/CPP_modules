#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include "colors.hpp"

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator= (const ScalarConverter &other);

	static bool _is_repeated(std::string str, char c);
	static bool _is_a_string(std::string str);
	static void _check_number_string(std::string str);
public:
	~ScalarConverter();
	static void convert(char *str);
};

#endif
