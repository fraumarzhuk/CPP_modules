#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include "colors.hpp"
#include <bits/stdc++.h>


class Span
{
private:
	unsigned int _N;
	std::vector<int> _vector;
public:
	Span(unsigned int N=0);
	Span(const Span &other);
	Span &operator= (const Span &other);
	~Span();
	class NoNumStored: public std::exception {
		public:
		const char* what() const throw() { return "Grade is too high!"; }
	}
	class NoNumStored: public std::exception {
		public:
		const char* what() const throw() { return "Grade is too high!"; }
	}
};

#endif
