#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	//std::cout << "BitcoinExchange Constructor called" << std::endl;
	parse_file(DATABASE, DATA_T);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	//std::cout << " BitcoinExchange Copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &other) {
	//std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	//std::cout << " BitcoinExchange Destructor called" << std::endl;
}

void BitcoinExchange::parse_file(std::string filename, int type) {
	std::ifstream file(filename.c_str());
	std::string first_line;
	std::getline(file, first_line, '\n');
	//std::cout << "line: "<< first_line << std::endl;
	FileChecker::is_correct_format(first_line, type);
}