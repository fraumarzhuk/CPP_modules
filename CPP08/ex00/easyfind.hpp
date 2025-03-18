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
	typename T::iterator pos =  std::find(first, last, victor);
	if (pos == last){
		std::cout << RED500 << "No occurrence found" << RESET << std::endl;
		return (-1);
	}
	return (pos - first);
}

#endif
 