#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange Constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	std::cout << " BitcoinExchange Copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other) {
	std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << " BitcoinExchange Destructor called" << std::endl;
}
