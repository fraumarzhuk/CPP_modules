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
		parsed[1] = line.substr(pos, line.length());

		//TODO:
		//write function to check float or int value get_value()
		if (type == DATA_T) {
			_database.insert(std::pair<std::string, float>(FileChecker::get_date(parsed[0]), 32.4f));
		}
		else if (type == INPUT_T) {
			_input.insert(FileChecker::get_date(line))
		}
		i++
	}
}