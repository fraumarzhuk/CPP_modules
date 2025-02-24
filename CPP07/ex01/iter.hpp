#ifndef ITER_HPP
#define ITER_HPP

#include "colors.hpp"

template<class A>

class Array{
public:
	Array();
	Array(unsigned int n);
	Array(const A &other);
	Array &operator= (const A &other);
	~Array();
	size();

};

#endif