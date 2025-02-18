#include <iostream>
#include "ScalarConverter.hpp"
#include <stdlib.h>


int main(int argc, char **argv) {

	(void) argc;
	ScalarConverter::convert(argv[1]);
	std::cout << "atof: " << atof(argv[1]) << std::endl;
	
}
