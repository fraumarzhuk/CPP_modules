#ifndef FILECHECKER_HPP
#define FILECHECKER_HPP
#include <iostream>
#include "colors.hpp"
#include <fstream>
#include <stdlib.h>

#define DATA "date,exchange_rate"
#define INPUT "date | value"
#define DATABASE "data.csv"

#include "BitcoinExchange.hpp"
class FileChecker {
private:
	/*OCF*/
	FileChecker(const FileChecker &other);
	FileChecker &operator= (const FileChecker &other);
	~FileChecker();
	FileChecker();

	/*members*/
	static void open_check(std::string filename);
	bool is_file_char(char c, std::string filename);
public:
	static bool is_correct_format(std::string line, char delimeter);
	static void error_exit(std::string error);
	static void file_check(std::string file);
	static void check_date(std::string line, char delimeter);
	// void contents_parse(std::string type);
};

#endif
