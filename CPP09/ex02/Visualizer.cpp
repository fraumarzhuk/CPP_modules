// #include "PmergeMe.hpp"
#include <iostream>
#include "colors.hpp"
#include <vector>
#include <deque>
#include <stdlib.h>

void print_pairs(std::vector<std::pair<int, int> > main_arg) {
	typename std::vector<std::pair<int, int> >::iterator a_it_b = main_arg.begin();
	typename std::vector<std::pair<int, int> >::iterator a_it_e = main_arg.end();
	
	//separate to pairs
	while (a_it_b < a_it_e) {
		std::cout << "[" << (*a_it_b).first << "," << (*a_it_b).second << "], ";
		a_it_b++;
	}
	std::cout << std::endl;

}