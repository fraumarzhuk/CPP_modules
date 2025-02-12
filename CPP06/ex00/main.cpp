#include <iostream>
#include "ScalarConverter.hpp"
#include <stdlib.h>

/*
	Check if empty input
	0. == invalid
	9.e
	1.2e-1+ or  with -

*/

int main(int argc, char **argv) {

	(void) argc;
	ScalarConverter::convert(argv[1]);
	std::cout << "atof: " << atof(argv[1]) << std::endl;
	
}

//std::fixed
//std;;precision

//str ->invalid input