#ifndef FILECHECKER_HPP
#define FILECHECKER_HPP
#include <iostream>
#include "colors.hpp"
#include <fstream>
#include <stdlib.h>

#define DATA "date,exchange_rate"
#define INPUT "date | value"
#define DATABASE "data.csv"

class FileChecker {
private:

	/*OCF*/
	FileChecker(const FileChecker &other);
	FileChecker &operator= (const FileChecker &other);
	~FileChecker();
	FileChecker();

	/*members*/
	static void error_exit(std::string error);
	static void open_check(std::string filename);
public:
	static void file_check(std::string file);
	// void contents_parse(std::string type);
};

#endif
