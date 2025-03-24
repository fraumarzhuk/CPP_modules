#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include "colors.hpp"
#include "FileChecker.hpp"
#include <map>

#define DATA_T 44
#define INPUT_T 124
class BitcoinExchange
{
private:
	std::multimap<std::string, float> _database;
	std::multimap<std::string, float> _input;

	/*OCF*/
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator= (const BitcoinExchange &other);
	void parse_file(std::string filename, int type);

public:
	BitcoinExchange();
	~BitcoinExchange();
};

#endif
