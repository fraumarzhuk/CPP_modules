#include "RPN.hpp"
#include <iostream>

#define MAXCHARS 1000
int main() {

	while (true) {
		std::string input;
		std::cout << CYAN500 << "> Enter your RPN string:" << RESET << std::endl;
		//std::cin.clear();
		std::getline(std::cin, input);
		if (!RPN::is_correct_input(input))
			continue ;
		float res = RPN::process_expr(input);
		std::cout << CYAN500 << "> Result: " << BLUE500 << res <<  RESET << std::endl;
	}
	return 0;
}