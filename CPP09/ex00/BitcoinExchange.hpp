#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include "colors.hpp"
#include "FileChecker.hpp"
#include <map>

#define DATA_T 44
#define INPUT_T 124
#define BITCOIN_START_YEAR 2009
#define CURRENT_YEAR 2025


inline bool operator<(const struct tm& fst, const struct tm& other) {
	if (fst.tm_year != other.tm_year) return fst.tm_year < other.tm_year;
	if (fst.tm_mon != other.tm_mon) return fst.tm_mon < other.tm_mon;
	return fst.tm_mday < other.tm_mday;
}

class BitcoinExchange {
private:
	/*members*/
	std::multimap<struct tm, float> _database;
	std::multimap<struct tm, float> _input;

	void parse_file(std::string filename, int type);
	float get_exchange_rate(struct tm date);
	
	/*OCF*/
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator= (const BitcoinExchange &other);
	
public:
	void print_result(struct tm date, std::string date_line, float val);
	BitcoinExchange(std::string filename);
	~BitcoinExchange();
};

#endif
