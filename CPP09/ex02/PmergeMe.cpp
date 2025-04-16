#include "PmergeMe.hpp"

// int _num_el;
// template <class Container>
// Container PmergeMe<Container>::_rest_line;
// template <class Container>
// Container PmergeMe<Container>::_down_line;
// template <class Container>
// Container PmergeMe<Container>::_up_line;
// template <class Container>
// Container PmergeMe<Container>::_vect_cont; //change this to T if doesnt work


// template <class Container>
// PmergeMe<Container>::PmergeMe() {
// 	//std::cout << "PmergeMe Constructor called" << std::endl;
// }

// template <class Container>
// PmergeMe<Container>::~PmergeMe() {
// 	//std::cout << "PmergeMe Destructor called" << std::endl;
// }

// template <class Container>
// PmergeMe<Container>::PmergeMe(const PmergeMe &other) {
// 	//std::cout << " PmergeMe Copy constructor called" << std::endl;
// }

// template <class Container>
// PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other) {
// 	//std::cout << "PmergeMe Copy assignment operator called" << std::endl;
// 	return (*this);
// }

// template <class Container>
// void PmergeMe<Container>::sort_vector(Container main_arg){
// 	vec_it a_it_b = main_arg.begin();
// 	vec_it a_it_e = main_arg.end();

// 	struct timeval begin, end;
//     gettimeofday(&begin, 0);
// 	//separate to pairs
// 	while (a_it_b < a_it_e) {
// 		if ((a_it_b + 1) != a_it_e) {
// 			std::pair<int, int> cur = std::make_pair(*a_it_b, *(a_it_b + 1));
// 			if (cur.first > cur.second)
// 				std::swap(cur.second, cur.first);
// 			_vect_cont.push_back(cur);
// 		} else 
// 			_rest_line.push_back(*a_it_b);
// 		a_it_b += 2;
// 	}
// 	insertion_sort(_vect_cont);
// 	_place_into_cont();
// 	add_up_line();
// 	binary_search();
// 	gettimeofday(&end, 0);
// 	std::cout << CYAN300 << "Before: " << RESET;
// 	Visualizer::print_sequence(main_arg);
// 	std::cout << LIME300 << "After: "<< RESET;
// 	Visualizer::print_sequence(_up_line);
// 	double dif = (end.tv_sec * 1000 * 1000 + end.tv_usec) - (begin.tv_sec * 1000 * 1000 + begin.tv_usec);
// 	std::cout << "time to process a range of " << _num_el << " elements with std::vector : " << PURPLE400  << dif << RESET <<" us" << std::endl;
	
// 	// return (_up_line);
// }

// template <class Container>
// void PmergeMe<Container>::_place_into_cont()
// {
// 	std::vector<std::pair<int, int> >::iterator a_it_b = _vect_cont.begin();
// 	std::vector<std::pair<int, int> >::iterator a_it_e = _vect_cont.end();

// 	while (a_it_b < a_it_e) {
// 		_down_line.push_back(a_it_b->first);
// 		_up_line.push_back(a_it_b->second);
// 		a_it_b++;
// 	}
// 	if (!_rest_line.empty())
// 		_down_line.push_back(_rest_line[0]);
// }

// template <class Container>
// void PmergeMe<Container>::insertion_sort(Container &pair_line) {
// 	int n = pair_line.size();
// 	for (int i = 1; i < n; i++) {
// 		std::pair<int, int> key = pair_line[i];
// 		int j = i - 1;
// 		while (j >= 0 && pair_line[j].second > key.second) {
// 			pair_line[j + 1] = pair_line[j];
// 			j = j - 1;
// 		}
// 		pair_line[j + 1] = key;
// 	}
// }

// template <class Container>
// void PmergeMe<Container>::add_up_line() {
// 	_up_line.insert(_up_line.begin(), *_down_line.begin());
// 	_down_line.erase(_down_line.begin());
// }

// template <class Container>
// void PmergeMe<Container>::binary_search() {
// 	if (_down_line.empty())
// 		return;
// 	int ins_num = *_down_line.begin();
// 	int high = _up_line.size() - 1;
// 	int low = 0;
	
// 	while (low <= high) {
// 	int mid = floor((high + low) / 2);
// 	if (mid < 1) {
// 		if (_up_line[0] > ins_num)
// 			_up_line.insert(_up_line.begin(), ins_num);
// 		else 
// 			_up_line.insert(_up_line.begin() + 1, ins_num);
// 		break;
// 	}
// 	if (is_correct_index(ins_num, mid))
// 		break;
// 	else if (_up_line[mid] < ins_num)
// 		low = mid + 1;
// 	else
// 		high = mid - 1;
// 	}
// 	_down_line.erase(_down_line.begin());
// 	//Visualizer::print_schema(_down_line, _up_line);
// 	binary_search();
// }

// template <class Container>
// bool PmergeMe<Container>::is_correct_index(int target_num, int mid) {
// 	if (_up_line[mid] == target_num) {
// 		_up_line.insert(_up_line.begin() + mid, target_num);
// 		return true;
// 	}
// 	if (_up_line[mid - 1] < target_num && target_num < _up_line[mid]) {
// 		_up_line.insert(_up_line.begin() + mid, target_num);
// 		return true;
// 	}
// 	return false;
// }


//combine into the main chain(up) 1st element of down, place it at [0] + up
//insert downline[0] to up using jacobsthal(?) and binary insertion(!)
//question: when exactly do we insert the remaining number?

//TODO:
//4. add time
//5. do deque