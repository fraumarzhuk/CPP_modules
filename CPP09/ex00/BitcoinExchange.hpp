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

struct Date {
	int year;
	int month;
	int day;
	bool operator<(const Date& other) const {
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
    }
};

class BitcoinExchange
{
private:
	std::multimap<Date, float> _database;
	std::multimap<Date, float> _input;

	/*OCF*/
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator= (const BitcoinExchange &other);
	void parse_file(std::string filename, int type);
	const float get_exchange_rate(Date date);

public:
	BitcoinExchange();
	~BitcoinExchange();
};

#endif
