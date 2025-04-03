#include "PmergeMe.cpp"
#include <iostream>
#include <vector>
#include "colors.hpp"

void error_exit(std::string msg) {
	std::cout << RED500 << msg << std::endl;
	exit (1);
}

std::vector<int> get_argument(int argc, char **argv) {
	if (argc < 2)
		error_exit("incorrect amount of arguments!");
	std::vector<int> res;
	for (int i = 1; i < argc; i++) {
		int j = atoi(argv[i]);
		if (j >= 0)
			res.push_back(j);
		else
			error_exit("negative numbers are not allowed!");
	}
	return res;
}

int main (int argc, char **argv) {
	std::vector<int> expr = get_argument(argc, argv);
	std::vector res = PmergeMe<int>::_pair_sort(expr);
}