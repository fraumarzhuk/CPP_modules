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
template <typename T, template<typename> class Container>

class PmergeMe {
private:
	static Container<std::pair<int, int> > _vect_cont;
	static Container<T> _up_line;
	static Container<T> _down_line;
	static Container<T> _rest_line;

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator= (const PmergeMe &other);
	~PmergeMe();
public:
	static void sort_vector(Container<int> main_arg); //move to private after testing
	static void _place_into_cont();
	static void insertion_sort(Container<std::pair<T, T>> &pair_line);
	static void add_up_line();
	static void binary_search();
	static bool is_correct_index(int target_num, int mid);
	//static T sort_sequence();
};

#endif

