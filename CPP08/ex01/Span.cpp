#include "Span.hpp"

Span::Span(unsigned int N) {
	if (N > _vector.max_size())
		throw VectorTooBig();
	_vector.reserve(N);
	//std::cout << "Span Constructor called" << std::endl;
}

Span::Span(const Span &other) {
	//std::cout << " Span Copy constructor called" << std::endl;
	*this = other;
}

Span &Span::operator = (const Span &other) {
	std::cout << "Span Copy assignment operator called" << std::endl;
	if (this != &other)
		_vector = other._vector;
	return (*this);
}

Span::~Span() {
	//std::cout << "Span Destructor called" << std::endl;
}

void Span::addNumber(int num) {
	if (_vector.size() == _vector.capacity())
		throw SpanIsFull();
	_vector.push_back(num);
	
}

int Span::shortestSpan() {
	if (_vector.size() == 0 || _vector.size() == 1)
		throw NoNumStored();
	std::sort(_vector.begin(), _vector.end());
	int short_dif = INT_MAX;
	for (size_t i = 0; i < _vector.size() - 1; i++) {
		int span = _vector[i + 1] - _vector[i];
		if (span < short_dif)
			short_dif = span;
	}
	return (short_dif);

}

int Span::longestSpan() {
	if (_vector.size() == 0 || _vector.size() == 1)
		throw NoNumStored();
	std::vector<int>::iterator min = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::iterator max = std::max_element(_vector.begin(), _vector.end());
	return (*max - *min); 
}