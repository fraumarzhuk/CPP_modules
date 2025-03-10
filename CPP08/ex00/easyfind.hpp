#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <vector>
#include "colors.hpp"
#include <bits/stdc++.h>

template <typename T>
int easyfind(T hextech, int victor) {

	typename T::iterator first = hextech.begin();
	typename T::iterator last = hextech.end();
	int pos = 0;
	while (first != last){
		if (*first == victor)
			return (pos);
		first++;
		pos++;
	}
	std::cout << RED500 << "No occurrence found" << RESET << std::endl;
	return (-1);
}

#endif
 