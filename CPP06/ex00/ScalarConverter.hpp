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
public:
	~ScalarConverter();

	static void convert(char *str);
};
#endif
