#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_rest_line;
std::vector<int> PmergeMe::_down_line;
std::vector<int> PmergeMe::_up_line;
std::vector<std::pair<int, int> > PmergeMe::_vect_cont;

PmergeMe::PmergeMe() {
	//std::cout << "PmergeMe Constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	//std::cout << " PmergeMe Copy constructor called" << std::endl;
	*this = other;
}

PmergeMe &PmergeMe::operator = (const PmergeMe &other) {
	//std::cout << "PmergeMe Copy assignment operator called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

// PmergeMe::~PmergeMe() {
// 	//std::cout << " PmergeMe Destructor called" << std::endl;
// }

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

// template <typename T>
// std::vector<T> PmergeMe<T>::_pair_sort(std::vector<T> main_arg) {
// 	typename std::vector<T>::iterator a_it_b = main_arg.begin();
// 	typename std::vector<T>::iterator a_it_e = main_arg.end();

// 	if (main_arg.size() <= 2)
// 		return main_arg;
// 	std::vector<std::pair<T, T> > _vect_cont;
// 	while (a_it_b < a_it_e) {
// 		if ((a_it_b + 1) != a_it_e) {
// 			std::pair<T, T> cur = std::make_pair(*a_it_b, *(a_it_b + 1));
// 			if (cur.first > cur.second)
// 				std::swap(cur.first, cur.second);
// 			_vect_cont.push_back(cur);
// 		} else
// 			_vect_cont.push_back(std::make_pair(*a_it_b, T()));
// 		a_it_b += 2;
// 	}
// 	std::vector<T> test;
// 	for (typename std::vector<std::pair<T, T> >::iterator it = _vect_cont.begin(); it != _vect_cont.end(); ++it) {
// 		test.push_back(it->first);
// 		if (it->second != T())
// 			test.push_back(it->second);
// 	}
// 	return _pair_sort(test);
// }

// if (cur.first > cur.second)
// std::swap(cur.first, cur.second);

//to think: maybe its not neede to separate them into pairs, just separate to two containers from the beginning

std::vector<std::pair<int, int> > PmergeMe::_pair_up(std::vector<int> main_arg) {
	typename std::vector<int>::iterator a_it_b = main_arg.begin();
	typename std::vector<int>::iterator a_it_e = main_arg.end();

	//separate to pairs
	while (a_it_b < a_it_e) {
		if ((a_it_b + 1) != a_it_e) {
			std::pair<int, int> cur = std::make_pair(*a_it_b, *(a_it_b + 1));
			if (cur.first > cur.second)
				std::swap(cur.second, cur.first);
			_vect_cont.push_back(cur);
		} else 
			_rest_line.push_back(*a_it_b);
		a_it_b += 2;
	}
	Visualizer::print_pairs(_vect_cont);
	if (!_rest_line.empty())
		std::cout << "remaining number: " << *(_rest_line.end() - 1) << std::endl;
	_place_into_cont();
	insertion_sort(_up_line);
	Visualizer::print_schema(_down_line, _up_line);
	return (_vect_cont);

}
void PmergeMe::_place_into_cont() {
	typename std::vector<std::pair<int, int> >::iterator a_it_b = _vect_cont.begin();
	typename std::vector<std::pair<int, int> >::iterator a_it_e = _vect_cont.end();

	while (a_it_b < a_it_e) {
		_down_line.push_back(a_it_b->first);
		_up_line.push_back(a_it_b->second);
		a_it_b++;
	}
	Visualizer::print_schema(_down_line, _up_line);
}

void PmergeMe::insertion_sort(std::vector<int> &up) {
    int n = up.size();
    for (int i = 1; i < n; i++) {
        int key = up[i];
        int j = i - 1;

        while (j >= 0 && up[j] > key) {
            up[j + 1] = up[j];
            j = j - 1;
        }
        up[j + 1] = key;
    }
}


//combine into the main chain(up) 1st element of down, place it at [0] + up
//insert downline[0] to up using jacobsthal(?) and binary insertion(!)
//question: when exactly do we insert the remaining number?