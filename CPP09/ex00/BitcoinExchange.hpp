#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include "colors.hpp"

class BitcoinExchange
{
private:
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator= (const BitcoinExchange &other);

public:
	BitcoinExchange();
	~BitcoinExchange();
};
#endif

