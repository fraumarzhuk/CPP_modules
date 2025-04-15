#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include "colors.hpp"
#include <vector>
#include <deque>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <algorithm>
#include "Visualizer.hpp"
#include "time.h"
#include <sys/time.h>

typedef std::vector<int>::iterator vec_it;

class PmergeMe {
private:
	static std::vector<std::pair<int, int> > _vect_cont;
	static std::deque<std::pair<int, int> > _deq_cont;
	static std::vector<int> _up_line;
	static std::vector<int> _down_line;
	static std::vector<int> _rest_line;

	static std::deque<int> _d_up_line;
	static std::deque<int> _d_down_line;
	static std::deque<int> _d_rest_line;

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator= (const PmergeMe &other);
	~PmergeMe();
public:
	static std::vector<int> sort_vector(std::vector<int> main_arg); //move to private after testing
	static void _place_into_cont();
	static void insertion_sort(std::vector<std::pair<int, int> > &pair_line);
	static void add_up_line();
	static void binary_search();
	static bool is_correct_index(int target_num, int mid);
	//static T sort_sequence();
};

#endif

