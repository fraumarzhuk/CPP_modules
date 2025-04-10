#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include "colors.hpp"
#include <vector>
#include <deque>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include "Visualizer.hpp"

class PmergeMe {
private:
	static std::vector<std::pair<int, int> > _vect_cont;
	static std::deque<std::pair<int, int> > _deq_cont;
	static std::vector<int> _up_line;
	static std::vector<int> _down_line;
	static std::vector<int> _rest_line; //change to remaining num int?

	
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator= (const PmergeMe &other);
	~PmergeMe();
public:
	static std::vector<std::pair<int, int> > _pair_up(std::vector<int> main_arg); //move to private after testing
	static void _place_into_cont();
	static void insertion_sort(std::vector<int> &up);
	static void add_up_line();
	static void binary_search();
	static bool is_correct_index(int target_num, int mid);
	//static T sort_sequence();
};

#endif

