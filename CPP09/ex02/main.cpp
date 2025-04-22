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

bool	compare_arrays(const std::vector<int> &arr1, const std::vector<int> &arr2) {
	if (arr1.size() != arr2.size())
		return false;

	for (size_t i = 0; i < arr1.size(); ++i) {
		if (arr1[i] != arr2[i]) {
			std::cout << "arr1[i] == " << arr1[i] << std::endl;
			std::cout << "arr2[i] == " << arr2[i] << std::endl;
			return false;
		}
	}
	return true;
}

int main (int argc, char **argv) {
	std::vector<int> expr_vec = get_argument(argc, argv);
	std::vector<int> sorted_by_algorithms = expr_vec;
	expr_vec = PmergeMe<std::vector>::sort_vector(expr_vec);
	std::deque<int> expr_deq(expr_vec.begin(), expr_vec.end());
	PmergeMe<std::deque>::sort_vector(expr_deq);

	std::sort(sorted_by_algorithms.begin(), sorted_by_algorithms.end());
	if (compare_arrays(expr_vec, sorted_by_algorithms)) {
		std::cout << "Sorted!\n";
	} else {
		std::cout << "failed to sort\n";
	}
	return 0;
}

//TODO:
//1. add jacobsthal
//2. make sure us seconds are correct
//3. one more check for error handling