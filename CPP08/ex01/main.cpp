#include "easyfind.hpp"
#include <iostream>



int main()
{
	const size_t N = 5;
	int a[N] = { 4, 32, -5, 42, 5 };
	std::vector<int> myarr(&a[0], &a[N]);
	int pos = easyfind(myarr, 42);
	std::cout << "42 found at position: "<<  pos << std::endl;
	pos = easyfind(myarr, 0);
	pos = easyfind(myarr, 5);
	std::cout << "42 found at position: "<<  pos << std::endl;
	return 0;
}