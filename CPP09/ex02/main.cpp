#include "PmergeMe.hpp"
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
		if (j >= 0 && std::find(res.begin(), res.end(), j) == res.end())
			res.push_back(j);
		else
			error_exit("negative numbers or duplicates are not allowed!");
	}
	return res;
}

int main (int argc, char **argv) {
	std::vector<int> expr = get_argument(argc, argv);
	std::vector<std::pair<int, int> > res = PmergeMe::_pair_up(expr);
	// Visualizer::print_pairs(res);
	// std::cout << "Sorted result: ";
	// for (std::vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	std::cout << std::endl;
}