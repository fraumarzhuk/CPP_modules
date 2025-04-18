#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP
#include <iostream>
#include "colors.hpp"
#include <vector>

template <template <typename, typename> class Container>
class Visualizer
{
private:
	Visualizer();
	Visualizer(const Visualizer &other);
	Visualizer &operator= (const Visualizer &other);
	~Visualizer();
	typedef typename Container<int, std::allocator<int> >::iterator cont_it;
public:
	static void print_pairs(Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > main_arg);
	static void print_schema(Container<int, std::allocator<int> >  down, Container<int, std::allocator<int> > up);
	static void print_sequence(Container<int, std::allocator<int> > line);
};


template <template <typename, typename> class Container>
Visualizer<Container>::~Visualizer() {
	std::cout << " Visualizer Destructor called" << std::endl;
}

template <template <typename, typename> class Container>
void Visualizer<Container>::print_pairs(Container<std::pair<int, int>, std::allocator<std::pair<int, int> > > main_arg) {
	cont_it a_it_b = main_arg.begin();
	cont_it a_it_e = main_arg.end();
	
	while (a_it_b < a_it_e) {
		std::cout << "[" << (*a_it_b).first << "," << (*a_it_b).second << "] ";
		a_it_b++;
	}
	std::cout << std::endl;

}

template <template <typename, typename> class Container>
void Visualizer<Container>::print_schema(Container<int, std::allocator<int> >  down, Container<int, std::allocator<int> > up) {
	cont_it a_it_b = up.begin();
	cont_it a_it_e = up.end();
	
	std::cout << std::endl;
	while (a_it_b < a_it_e) {
		std::cout << *a_it_b << "—";
		a_it_b++;
	}
	std::cout << std::endl;
	a_it_b = down.begin();
	a_it_e = down.end();
	while (a_it_b < a_it_e) {
		std::cout <<  *a_it_b << "—";
		a_it_b++;
	}
	std::cout << std::endl;
}

template <template <typename, typename> class Container>
void Visualizer<Container>::print_sequence(Container<int, std::allocator<int> >  line) {
	for (cont_it it = line.begin(); it != line.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <template <typename, typename> class Container>
Visualizer<Container>::Visualizer() {
//std::cout << "Visualizer Constructor called" << std::endl;
}

template <template <typename, typename> class Container>
Visualizer<Container>::Visualizer(const Visualizer &other) {
	//std::cout << " Visualizer Copy constructor called" << std::endl;
	this = other;
}

template <template <typename, typename> class Container>
Visualizer<Container> &Visualizer<Container>::operator = (const Visualizer<Container> &other) {
	//std::cout << "Visualizer Copy assignment operator called" << std::endl;
	this = other;
	return (*this);
}

#endif
