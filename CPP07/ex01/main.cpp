#include <iostream>
#include <stdlib.h>
#include "iter.hpp"
#include <cstdio>
#include "colors.hpp"


void print_my_auto(std::string name) {
	std::cout << "My fav car is " << name << std::endl;
}

void print_my_num(int num) {
	std::cout << "My fav num is " << num << std::endl;
}


int main( void ) {
	std::cout << BG_BLUE300 LIME600 << "Array of strings:" << RESET << std::endl;
	std::string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
	::iter(cars, 4, print_my_auto);

	std::cout << BG_BLUE300  LIME600 << "Array of ints:" << RESET << std::endl;
	int numbers[5] = {1, 2, 3, 4, 5};
	::iter(numbers, 5, print_my_num);

	return 0;
	}