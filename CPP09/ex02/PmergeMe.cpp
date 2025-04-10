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
	add_up_line();
	Visualizer::print_schema(_down_line, _up_line);
	binary_search();
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

void PmergeMe::add_up_line() {
	_up_line.insert(_up_line.begin(), *_down_line.begin());
	_down_line.erase(_down_line.begin());
	//append the last num of the downline here?
	//_down_line.push_back(*_rest_line.begin());
}

void PmergeMe::binary_search() {
	if (_down_line.empty())
		return ;
	int ins_num = *_down_line.begin();
	int high = _up_line.size() - 1;
	int low = 0;
	while (low <= high) {
		int mid = floor((high + low) / 2);
		if (is_correct_index(ins_num, mid)) {
			_down_line.erase(_down_line.begin());
			break; 
		}
		else if (_up_line[mid] < ins_num)
			low = mid + 1;
		else 
			high = mid - 1;
	}
	std::cout << "Binary search: " << std::endl;
	Visualizer::print_schema(_down_line, _up_line);
	binary_search();
}

bool PmergeMe::is_correct_index(int target_num, int mid) {
	if (_up_line[mid] == target_num) {
		_up_line.insert(_up_line.begin() + mid, target_num);
		return true;
	}
	if (_up_line[mid - 1] > target_num && target_num < _up_line[mid]) {
		_up_line.insert(_up_line.begin() + (mid - 1), target_num);
		return true;
	}
	return (false);
}

//combine into the main chain(up) 1st element of down, place it at [0] + up
//insert downline[0] to up using jacobsthal(?) and binary insertion(!)
//question: when exactly do we insert the remaining number?

//TODO:
//1. handle " arg"
//2. handle duplicates??? are they allowed
//3.handle max int
