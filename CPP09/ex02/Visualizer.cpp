#include "Visualizer.hpp"

// Visualizer::Visualizer()
// {
// std::cout << "Visualizer Constructor called" << std::endl;
// }

// Visualizer::Visualizer(const Visualizer &other)
// {
// 	std::cout << " Visualizer Copy constructor called" << std::endl;
// 	*this = other;
// }

// Visualizer &Visualizer::operator = (const Visualizer &other)
// {
// 	std::cout << "Visualizer Copy assignment operator called" << std::endl;
// 	if (this != &other)
// 	{
// 		//assign;
// 	}
// 	return (*this);
// }

// Visualizer::~Visualizer()
// {
// 	std::cout << " Visualizer Destructor called" << std::endl;
// }

// void Visualizer::print_pairs(std::vector<std::pair<int, int> > main_arg) {
// 	typename std::vector<std::pair<int, int> >::iterator a_it_b = main_arg.begin();
// 	typename std::vector<std::pair<int, int> >::iterator a_it_e = main_arg.end();
	
// 	while (a_it_b < a_it_e) {
// 		std::cout << "[" << (*a_it_b).first << "," << (*a_it_b).second << "] ";
// 		a_it_b++;
// 	}
// 	std::cout << std::endl;

// }

// void Visualizer::print_schema(std::vector<int> down, std::vector<int> up) {
// 	std::vector<int>::iterator a_it_b = up.begin();
// 	std::vector<int>::iterator a_it_e = up.end();
	
// 	std::cout << std::endl;
// 	while (a_it_b < a_it_e) {
// 		std::cout << *a_it_b << "—";
// 		a_it_b++;
// 	}
// 	std::cout << std::endl;
// 	a_it_b = down.begin();
// 	a_it_e = down.end();
// 	while (a_it_b < a_it_e) {
// 		std::cout <<  *a_it_b << "—";
// 		a_it_b++;
// 	}
// 	std::cout << std::endl;
// }
// void Visualizer::print_sequence(std::vector<int> line) {
// 	for (std::vector<int>::iterator it = line.begin(); it != line.end(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }