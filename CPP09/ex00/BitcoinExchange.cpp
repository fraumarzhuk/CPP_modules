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


	// FileChecker::_correctline = true;
	FileChecker::_line_num = 1;
	FileChecker::is_correct_format(line, type);
	while (std::getline(file, line)) {
		FileChecker::_line_num++;
		if (line.empty()){
			FileChecker::error_exit("empty line");
			continue ;
		}
		int pos = line.find(type);
		parsed[0] = line.substr(0, pos);
		parsed[1] = line.substr(pos + 1, line.length());

		struct tm date;
		FileChecker::get_date(parsed[0], date);
		float value = FileChecker::get_value(parsed[1], filename);
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
	}
	file.close();
}

float BitcoinExchange::get_exchange_rate(struct tm date) {
	std::multimap<struct tm, float>::iterator begin = _database.begin();
	std::multimap<struct tm, float>::iterator end = _database.end();

	float rate = 0;
	time_t date_tstamp = mktime(&date);
	while (begin != end) {
		struct tm temp_tm = begin->first;
		time_t temp = mktime(&temp_tm);
		if (temp <= date_tstamp) {
			rate = begin->second;
		} else
			break;
		begin++;
	}
	return (rate);
}

void BitcoinExchange::print_result(struct tm date, std::string date_line, float val) {
	float res = get_exchange_rate(date) * val;
	std::cout << date_line << " => " << val << " = " << res <<  std::endl;
}
