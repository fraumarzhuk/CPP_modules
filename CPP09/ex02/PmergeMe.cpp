#include "PmergeMe.hpp"

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

PmergeMe::~PmergeMe() {
	//std::cout << " PmergeMe Destructor called" << std::endl;
}

//step 1 get them into pairs

void PmergeMe::_pair_sort(std::vector<int> main_arg) {
	std::vector<int>::iterator a_it_b = main_arg.begin();
	std::vector<int>::iterator a_it_e = main_arg.end();

	while (a_it_b < a_it_e) {
		if ((a_it_b + 1) != a_it_e) {
			std::pair<int, int> cur = std::make_pair(*a_it_b, *(a_it_b + 1));
			if (cur.first > cur.second)
				std::swap(cur.first, cur.second);
			_vect_cont.push_back(cur);
		}
		a_it_b += 2;
	}
	//the last number??? what to do with it? check later
}