#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include "colors.hpp"
#include <vector>
#include <deque>
#include <stdlib.h>
//#include "Visualizer.hpp"

class PmergeMe {
private:
	//static std::vector<std::pair<int, int> > _vect_cont;
	static std::deque<std::pair<int, int> > _deq_cont;
	static std::vector<int> _up_line;
	static std::vector<int> _down_line;
	static std::vector<int> _rest;

	
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator= (const PmergeMe &other);
	~PmergeMe();
public:
	static std::vector<std::pair<int, int> > _pair_up(std::vector<int> main_arg);
	//static T sort_sequence();
};

#endif
