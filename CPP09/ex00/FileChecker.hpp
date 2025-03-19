#ifndef FILECHECKER_HPP
#define FILECHECKER_HPP
#include <iostream>
#include "colors.hpp"
#include <fstream>
#include <stdlib.h>

class FileChecker
{
private:
	std::string _database;
	std::string _input; 
	FileChecker(const FileChecker &other);
	FileChecker &operator= (const FileChecker &other);
public:
	~FileChecker();
	FileChecker(std::string input);
	void open_check();
	void error_exit(std::string error);
};
#endif
