#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include "colors.hpp"
#include "limits.h"

void error_exit(std::string msg) {
	std::cout << RED500 << msg << std::endl;
	exit (1);
}

std::vector<int> get_argument(int argc, char **argv) {
	if (argc < 2)
		error_exit("incorrect amount of arguments!");
	if (argc == 2)
		error_exit("place the sequence in separate arguments bitte.");
	std::vector<int> res;
	for (int i = 1; i < argc; i++) {
		float j = atof(argv[i]);
		if (j >= 0 && std::find(res.begin(), res.end(), j) == res.end() && j <= INT_MAX)
			res.push_back(static_cast<int>(j));
		else
			error_exit("negative numbers, numbers bigger than INT_MAX  or duplicates are not allowed!");
	}
	return res;
}

int main (int argc, char **argv) {
	std::vector<int> expr = get_argument(argc, argv);
	std::vector<int> res = PmergeMe::_pair_up(expr);
	std::cout << std::endl;
}