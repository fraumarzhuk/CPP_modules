#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename) {
	//std::cout << "BitcoinExchange Constructor called" << std::endl;
	parse_file(DATABASE, DATA_T);
	parse_file(filename, INPUT_T);
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
	//std::cout << "line: " << line << std::endl;

	FileChecker::_correctline = true; // maybe create a getter for it
	FileChecker::_line_num = 1;
	FileChecker::is_correct_format(line, type);
	while (std::getline(file, line) && FileChecker::_correctline) {
		int pos = line.find(type);
		parsed[0] = line.substr(0, pos);
		parsed[1] = line.substr(pos + 1, line.length());

		struct tm date;
		date.tm_hour = 0;
		date.tm_min = 0;
		date.tm_sec = 0;
		FileChecker::get_date(parsed[0], date);
		float value = FileChecker::get_value(parsed[1], filename);
		// std::cout << "Value : " << value << std::endl;
		if (type == DATA_T)
			_database.insert(std::pair<struct tm, float>(date, value));
		else if (type == INPUT_T)
			_input.insert(std::pair<struct tm, float>(date, value));

		if (!FileChecker::_correctline && type == DATA_T)
			exit(1);
		if (type == INPUT_T && FileChecker::_correctline) {
			print_result(date, parsed[0], value);
		}
		FileChecker::_correctline = true;
		FileChecker::_line_num++;
	}
	file.close(); //?
}

float BitcoinExchange::get_exchange_rate(struct tm date) {
	std::multimap<struct tm, float>::iterator begin = _database.begin();
	std::multimap<struct tm, float>::iterator end = _database.end();

	float rate = 0;
	int dif = INT_MAX;
	time_t date_tstamp = mktime(&date);
	while (begin != end) {
		struct tm temp_tm = begin->first;
		//std::cout << "Begin->second: " <<begin->second << std::endl;
		time_t temp = mktime(&temp_tm);
		if (date_tstamp - temp < dif) {
			dif = temp - date_tstamp;
			rate = begin->second;
			//std::cout << "Begin->second: " <<begin->second << std::endl;
		}
		begin++;
	}
	return (rate);
}

void BitcoinExchange::print_result(struct tm date, std::string date_line, float val) {
	// std::cout << "Exchange rate: " << get_exchange_rate(date) << std::endl;
	// std::cout << "Value: " << val << std::endl;
	float res = get_exchange_rate(date) * val;
	std::cout << date_line << " => " << val << " = " << res <<  std::endl;
}
