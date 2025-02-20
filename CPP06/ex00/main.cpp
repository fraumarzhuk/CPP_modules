#include <iostream>
#include "ScalarConverter.hpp"
#include <stdlib.h>


int main(int argc, char **argv) {

	if (argc < 2)
		std::cerr << "INPUT BITTE "<< std::endl, exit(1);

	ScalarConverter::convert(argv[1]);
	std::cout << "atof: " << atof(argv[1]) << std::endl;
	
}
