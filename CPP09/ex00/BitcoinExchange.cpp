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
	if (this != &other) {
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

		Date date;
		FileChecker::get_date(parsed[0], date);
		float value = FileChecker::get_value(parsed[1], filename);
		std::cout << "date: "<< date.year << date.month << date.day << std::endl;
		if (type == DATA_T)
			_database.insert(std::pair<Date, float>(date, value));
		else if (type == INPUT_T)
			_input.insert(std::pair<Date, float>(date, value));
	}
}

//TODO:
// should dates be kept in strings ot maybe save them in a struct??
//create a print function that will output things nicely
//create an algorithm function that will find the closest date