#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include "colors.hpp"
#include <vector>
#include <deque>
#include <utility>
#include <sys/time.h>
#include <algorithm>
#include <cmath>
#include <typeinfo>
#include "Visualizer.hpp"

template <template <typename, typename> class Container>
class PmergeMe {
private:
	static Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > _vect_cont; // Adaptable container
	static Container<int, std::allocator<int> > _up_line;
	static Container<int, std::allocator<int> > _down_line;
	static Container<int, std::allocator<int> > _rest_line;
	// static struct timeval begin;
	// static struct timeval end;

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

public:
	static void sort_vector(Container<int, std::allocator<int> > main_arg); // Accepts adaptable container
	static void _place_into_cont();
	static void insertion_sort(Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > &pair_line);
	static void add_up_line();
	static void binary_search();
	static bool is_correct_index(int target_num, int mid);
	//static bool container_type(const Container<int, std::allocator<int> > &container);
	static void print_results(Container<int, std::allocator<int> > main_arg, struct timeval begin, struct timeval end);
};


// static struct timeval begin;
// static struct timeval end;

template <template <typename, typename> class Container>
Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > PmergeMe<Container>::_vect_cont;

template <template <typename, typename> class Container>
Container<int, std::allocator<int> > PmergeMe<Container>::_rest_line;

template <template <typename, typename> class Container>
Container<int, std::allocator<int> > PmergeMe<Container>::_down_line;

template <template <typename, typename> class Container>
Container<int, std::allocator<int> > PmergeMe<Container>::_up_line;


// template <template <typename, typename> class Container>
// bool PmergeMe<Container>::container_type(const Container<int, std::allocator<int> > &container) {
// 	return typeid(container) == typeid(std::vector<int>);
// }

template <template <typename, typename> class Container>
void PmergeMe<Container>::sort_vector(Container<int, std::allocator<int> > main_arg) {
	typename Container<int, std::allocator<int> >::iterator a_it_b = main_arg.begin();
	typename Container<int, std::allocator<int> >::iterator a_it_e = main_arg.end();

	struct timeval begin, end;
	gettimeofday(&begin, 0);
	while (a_it_b < a_it_e) {
		if ((a_it_b + 1) != a_it_e) {
			std::pair<int, int> cur = std::make_pair(*a_it_b, *(a_it_b + 1));
			if (cur.first > cur.second)
				std::swap(cur.first, cur.second);
			_vect_cont.push_back(cur);
		} else {
			_rest_line.push_back(*a_it_b);
		}
		a_it_b += 2;
	}
	insertion_sort(_vect_cont);
	_place_into_cont();
	add_up_line();
	binary_search();
	gettimeofday(&end, 0);
	print_results(main_arg, begin, end);
}

template <template <typename, typename> class Container>
// void PmergeMe<Container>::print_results(Container<int, std::allocator<int> > main_arg, struct timeval begin, struct timeval end) {
// 	std::cout << CYAN300 << "Before: " << RESET;
// 	Visualizer<Container<int, std::allocator<int> > >::print_sequence(main_arg);
// 	std::cout << LIME300 << "After: " << RESET;
// 	Visualizer<Container>::print_sequence(_up_line);
// 	double dif = (end.tv_sec * 1000 * 1000 + end.tv_usec) - (begin.tv_sec * 1000 * 1000 + begin.tv_usec);
// 	std::cout << "time to process a range of " << main_arg.size() << " elements: " << PURPLE400 << dif << RESET << " us" << std::endl;
// }

void PmergeMe<Container>::print_results(Container<int, std::allocator<int> > main_arg, struct timeval begin, struct timeval end) {
	std::cout << CYAN300 << "Before: " << RESET;
	Visualizer<Container<int, std::allocator<int> > >::print_sequence(main_arg); // Provide template arguments
	std::cout << LIME300 << "After: " << RESET;
	Visualizer<Container<int, std::allocator<int> > >::print_sequence(_up_line); // Provide template arguments
	double dif = (end.tv_sec * 1000 * 1000 + end.tv_usec) - (begin.tv_sec * 1000 * 1000 + begin.tv_usec);
	std::cout << "time to process a range of " << main_arg.size() << " elements: " << PURPLE400 << dif << RESET << " us" << std::endl;
}

template <template <typename, typename> class Container>
void PmergeMe<Container>::_place_into_cont()
{
	typename Container<std::pair<int, int>, std::allocator<std::pair<int, int> > >::iterator a_it_b = _vect_cont.begin();
	typename Container<std::pair<int, int>, std::allocator<std::pair<int, int> > >::iterator a_it_e = _vect_cont.end();

	while (a_it_b < a_it_e) {
		_down_line.push_back(a_it_b->first);
		_up_line.push_back(a_it_b->second);
		a_it_b++;
	}
	if (!_rest_line.empty())
		_down_line.push_back(_rest_line[0]);
}

template <template <typename, typename> class Container>
void PmergeMe<Container>::insertion_sort(Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > &pair_line) {
	int n = pair_line.size();
	for (int i = 1; i < n; i++) {
		std::pair<int, int> key = pair_line[i];
		int j = i - 1;
		while (j >= 0 && pair_line[j].second > key.second) {
			pair_line[j + 1] = pair_line[j];
			j = j - 1;
		}
		pair_line[j + 1] = key;
	}
}

template <template <typename, typename> class Container>
void PmergeMe<Container>::add_up_line() {
	_up_line.insert(_up_line.begin(), *_down_line.begin());
	_down_line.erase(_down_line.begin());
}

template <template <typename, typename> class Container>
void PmergeMe<Container>::binary_search() {
	if (_down_line.empty())
		return;
	int ins_num = *_down_line.begin();
	int high = _up_line.size() - 1;
	int low = 0;
	
	while (low <= high) {
	int mid = floor((high + low) / 2);
	if (mid < 1) {
		if (_up_line[0] > ins_num)
			_up_line.insert(_up_line.begin(), ins_num);
		else 
			_up_line.insert(_up_line.begin() + 1, ins_num);
		break;
	}
	if (is_correct_index(ins_num, mid))
		break;
	else if (_up_line[mid] < ins_num)
		low = mid + 1;
	else
		high = mid - 1;
	}
	_down_line.erase(_down_line.begin());
	binary_search();
}

template <template <typename, typename> class Container>
bool PmergeMe<Container>::is_correct_index(int target_num, int mid) {
	if (_up_line[mid] == target_num) {
		_up_line.insert(_up_line.begin() + mid, target_num);
		return true;
	}
	if (_up_line[mid - 1] < target_num && target_num < _up_line[mid]) {
		_up_line.insert(_up_line.begin() + mid, target_num);
		return true;
	}
	return false;
}

template <template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe() {
	//std::cout << "PmergeMe Constructor called" << std::endl;
}

template <template <typename, typename> class Container>
PmergeMe<Container>::~PmergeMe() {
	//std::cout << "PmergeMe Destructor called" << std::endl;
}

template <template <typename, typename> class Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) {
	//std::cout << " PmergeMe Copy constructor called" << std::endl;
}

template <template <typename, typename> class Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other) {
	//std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	return (*this);
}

#endif

