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
};

class BitcoinExchange
{
private:
	std::multimap<struct Date, float> _database;
	std::multimap<struct Date, float> _input;

	/*OCF*/
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator= (const BitcoinExchange &other);
	void parse_file(std::string filename, int type);

public:
	BitcoinExchange();
	~BitcoinExchange();
};

#endif
