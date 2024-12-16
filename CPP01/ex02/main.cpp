#include "colors.hpp"
#include <iostream>
#include <string>

int main(){
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	std::cout << "Memory address of brain: " << GREEN400 << &brain << RESET << std::endl;
	std::cout << "Memory address of stringPTR: " << EMERALD400 << stringPTR << RESET << std::endl;
	std::cout << "Memory address of stringREF: " << CYAN400 << &stringREF << RESET << std::endl << std::endl;
	std::cout << "The value of brain: " << GREEN400 << brain << RESET << std::endl;
	std::cout << "The value of stringPTR: " << EMERALD400 << *stringPTR << RESET << std::endl;
	std::cout << "The value of stringREF: " << CYAN400 << stringREF << RESET << std::endl << std::endl;
}