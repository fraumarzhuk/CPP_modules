#include "MutantStack.hpp"
#include <iostream>
#include "colors.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << CYAN600 << "Top :" << RESET <<std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << CYAN600 << "Popped one.Size :" << RESET <<std::endl;
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << CYAN600 << "Cur stack : 5 3 5 737 0" << RESET <<std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	MutantStack<int> s(mstack);
	std::cout << CYAN600 BG_LIME300 << "Copied stack, check that values are the same: " << RESET <<std::endl;
	std::cout << CYAN600 << "Cur stack : 5 3 5 737 0" << RESET <<std::endl;
	it = s.begin();
	ite = s.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << CYAN600 BG_LIME300 << "Created a regular stack, checking the values: " << RESET <<std::endl;
	std::stack<int> stand(mstack);
	while (!stand.empty()) {
		std::cout << stand.top() << std::endl;
		stand.pop();
	}
	return 0;
}