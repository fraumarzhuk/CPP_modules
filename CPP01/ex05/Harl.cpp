#include "Harl.hpp"

Harl::Harl() {
	this->level_funct_p[0] = &Harl::_debug;
	this->level_funct_p[1] = &Harl::_info;
	this->level_funct_p[2] = &Harl::_warning;
	this->level_funct_p[3] = &Harl::_error;
}

Harl::~Harl() {}

void Harl::_debug() {
	std::cout << INDIGO400 << "Some debugging is happening here. Your segfaults are so annoying" << RESET << std::endl;
}

void Harl::_info() {
	std::cout << LIME400 <<"This is a very important information message that contains nothing but this text" << RESET << std::endl;
}

void Harl::_warning() {
	std::cout << PINK400 << "Attention! Thanks for attention. You have been warned" << RESET << std::endl;
}

void Harl::_error() {
	std::cout << RED400 << "Errors are part of failing. Failing = learning. You'll be fine" << RESET << std::endl;
}

void Harl::complain(std::string level) {
	for(size_t i = 0; i < level.length(); i++)
    	level[i] = toupper(level[i]);
	std::string levels[NUM_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t i = 0;
	while (level != levels[i] && i < NUM_LEVELS) 
		i++;
	if (i == NUM_LEVELS)
	{
		std::cout << "Attention! Thanks for attention. You have been warned" << std::endl;
		return ;

	}
	(this->*level_funct_p[i])();
}