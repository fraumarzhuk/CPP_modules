#include "FileChecker.hpp"

#define DATA "date,exchange_rate"
#define INPUT "date | value"

FileChecker::FileChecker(std::string input): _database("data.csv"), _input(input) {
	//std::cout << "FileChecker Constructor called" << std::endl;
	open_check();
}

FileChecker::FileChecker(const FileChecker &other) {
	//std::cout << " FileChecker Copy constructor called" << std::endl;
	*this = other;
}

FileChecker &FileChecker::operator = (const FileChecker &other) {
	//std::cout << "FileChecker Copy assignment operator called" << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

FileChecker::~FileChecker() {
	//std::cout << " FileChecker Destructor called" << std::endl;
}

bool FileChecker::open_check() {
	std::ifstream input(_input.c_str());
	std::ifstream data(_database.c_str());
	if (!input || !data)
		error_exit("Error opening a file " + (input ? _database : _input));
	return true;
}

void FileChecker::error_exit(std::string error) {
	std::cerr << RED500 << error << std::endl;
	exit(1);
}