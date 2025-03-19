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

void FileChecker::open_check() {
	std::ifstream input(_input.c_str());
	std::ifstream data(_database.c_str());
	if (!input || !data)
		error_exit("Error opening/reading a file named: " + (input ? _database : _input));
	input.seekg(0, std::ios::end);
	data.seekg(0, std::ios::end);
	if (!input.tellg() || !data.tellg())
		error_exit("Empty file or database.");
	}
	
	void FileChecker::error_exit(std::string error) {
		std::cerr << RED500 << error << std::endl;
		exit(1);
	}
	
//first line fort database and for input check, then pass to parsing function