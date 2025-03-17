#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include "colors.hpp"
#include <stack>
template <typename T>
class MutantStack: public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typename MutantStack<T>::iterator begin();
	typename MutantStack<T>::iterator end();
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator= (const MutantStack &other);
	~MutantStack();

};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {
	std::cout << "MutantStack Constructor called" << std::endl;
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other): std::stack<T>() {
	std::cout << " MutantStack Copy constructor called" << std::endl;
	*this = other;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack<T> &other) {
	std::cout << "MutantStack Copy assignment operator called" << std::endl;
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << " MutantStack Destructor called" << std::endl;
}

#endif