#include "colors.hpp"
#include <iostream>
#include <string>

void change(std::string a) {
	a = "changed";
}

void change_ref(std::string &a) {
	a = "changed";
}

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

	std::string a = "before";
	change(a);
	std::cout << a << "\n"; //before
	a = "before";
	change_ref(a);
	std::cout << a << "\n"; //changed

	a = "before";
	std::string &b = a;
	change(b); 
	std::cout << b << "\n"; //changed ?
	a = "abc";
	std::cout << b << "\n"; //abc
	change_ref(b);
	std::cout << b << "\n"; //changed
	std::cout << a << "\n"; //changed
}