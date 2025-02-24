#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include "colors.hpp"

template <typename T>

void swap(T &a, T &b) {
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename M>
M max(const M a, const M b){
	if (a == b)
		return b;
	return (a < b? b : a);
}

template <typename N>
N min(const N a, const N b){
	if (a == b)
		return b;
	return (a < b? a : b);
}

#endif
