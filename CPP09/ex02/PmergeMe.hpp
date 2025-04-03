#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include "colors.hpp"

// template <typename T>

class PmergeMe {
private:
	static std::vector<std::pair<int, int>> _vect_cont;
	static std::deque<int> _deq_cont;

	void _pair_sort(std::vector<int> main_arg);

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator= (const PmergeMe &other);
	~PmergeMe();
public:
	//static T sort_sequence();
};

#endif
