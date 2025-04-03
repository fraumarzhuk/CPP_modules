#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe() {
	//std::cout << "PmergeMe Constructor called" << std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other) {
	//std::cout << " PmergeMe Copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator = (const PmergeMe &other) {
	//std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

template <typename T>
PmergeMe<T>::~PmergeMe() {
	//std::cout << " PmergeMe Destructor called" << std::endl;
}

//step 1 get them into pairs

// void PmergeMe::_pair_sort(std::vector<int> main_arg) {
// 	std::vector<int>::iterator a_it_b = main_arg.begin();
// 	std::vector<int>::iterator a_it_e = main_arg.end();

// 	while (a_it_b < a_it_e) {
// 		if ((a_it_b + 1) != a_it_e) {
// 			std::pair<int, int> cur = std::make_pair(*a_it_b, *(a_it_b + 1));
// 			if (cur.first > cur.second)
// 				std::swap(cur.first, cur.second);
// 			_vect_cont.push_back(cur);
// 		}
// 		a_it_b += 2;
// 	}
// 	//make pairs
// 	//separate
// 	//make pair
// 	//separate
// template <typename T>
// std::vector<std::pair<T, T> > PmergeMe<T>::_vect_cont;

template <typename T>
std::vector<T> PmergeMe<T>::_pair_sort(std::vector<T> main_arg) {
	typename std::vector<T>::iterator a_it_b = main_arg.begin();
	typename std::vector<T>::iterator a_it_e = main_arg.end();

	if (main_arg.size() <= 2)
		return main_arg;
	std::vector<std::pair<T, T> > _vect_cont;
	while (a_it_b < a_it_e) {
		if ((a_it_b + 1) != a_it_e) {
			std::pair<T, T> cur = std::make_pair(*a_it_b, *(a_it_b + 1));
			if (cur.first > cur.second)
				std::swap(cur.first, cur.second);
			_vect_cont.push_back(cur);
		} else
			_vect_cont.push_back(std::make_pair(*a_it_b, T()));
		a_it_b += 2;
	}
	std::vector<T> test;
	for (typename std::vector<std::pair<T, T> >::iterator it = _vect_cont.begin(); it != _vect_cont.end(); ++it) {
		test.push_back(it->first);
		if (it->second != T())
			test.push_back(it->second);
	}
	return _pair_sort(test);
}

