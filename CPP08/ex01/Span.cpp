#include "Span.hpp"

Span::Span(unsigned int N): _N(N) {
	// if (N == 0) {
	// 	std::cerr << RED500 << "Incorrect parameters" << RESET << std::endl;
	// 	return ;
	// }
	std::cout << "Span Constructor called" << std::endl;
}

Span::Span(const Span &other) {
	std::cout << " Span Copy constructor called" << std::endl;
	*this = other;
}

Span &Span::operator = (const Span &other) {
	std::cout << "Span Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_N = other._N;
		_vector = other._vector;
	}
	return (*this);
}

Span::~Span() {
	std::cout << " Span Destructor called" << std::endl;
}

void Span::addNumber() {

}