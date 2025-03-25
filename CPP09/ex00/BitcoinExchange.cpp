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
	std::string line;
	std::getline(file, line);
	std::string parsed[2];
	//std::cout << "line: "<< first_line << std::endl;

	FileChecker::is_correct_format(line, type); // chek first line

	while (std::getline(file, line)) {
		int pos = line.find(type);
		parsed[0] = line.substr(0, pos);
		parsed[1] = line.substr(pos + 1, line.length());
		// std::cout << "line 1: "<< parsed[0] << std::endl;
		// std::cout << "line 1: "<< parsed[1] << std::endl;
		if (type == DATA_T)
			_database.insert(std::pair<std::string, float>(FileChecker::get_date(parsed[0]), FileChecker::get_value(parsed[1], filename)));
		else if (type == INPUT_T)
			_input.insert(std::pair<std::string, float>(FileChecker::get_date(parsed[0]), FileChecker::get_value(parsed[1], filename)));
	}
}