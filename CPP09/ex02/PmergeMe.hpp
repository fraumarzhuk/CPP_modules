#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include "colors.hpp"

template <typename T>

class PmergeMe {
private:
	static std::vector<std::pair<int, int> > _vect_cont;
	static std::deque<std::pair<int, int> > _deq_cont;

	
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator= (const PmergeMe &other);
	~PmergeMe();
public:
	static std::vector<T> _pair_sort(std::vector<T> main_arg);
	//static T sort_sequence();
};

#endif
