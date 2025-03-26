#include "FileChecker.hpp"

bool FileChecker::_correctline = true;

FileChecker::FileChecker() {
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

void FileChecker::open_check(std::string filename) {
	std::string database = DATABASE;
	std::ifstream input(filename.c_str());
	std::ifstream data(database.c_str());
	if (!input || !data)
		error_exit("Error opening/reading a file named: " + (input ? database : filename));
	input.seekg(0, std::ios::end);
	data.seekg(0, std::ios::end);
	if (!input.tellg() || !data.tellg())
		error_exit("Empty file or database.");
}
	
void FileChecker::error_exit(std::string error) {
	std::cerr << RED500 << error << std::endl;
	_correctline = false;
	//exit(1);
}

void FileChecker::file_check(std::string file) {
	open_check(file);

}
bool FileChecker::is_correct_format(std::string line, char delimeter) {
	if (delimeter == DATA_T && line.compare(DATA))
		error_exit("Incorrect format of file. Correct format should be " + static_cast<std::string>(DATA));
	else if (delimeter == INPUT_T && line.compare(INPUT))
		error_exit("Incorrect format of data file  Correct format should be " + static_cast<std::string>(INPUT));
	return (true);	
}

//attention this function only checks separated parts before and after delimeter
bool FileChecker::is_file_char(char c, std::string filename) {
	if (isdigit(c) || c == '-' || c == '.' )
		return true;
	error_exit("Incorrect format of the " + filename + " file. Found char: " + c);
	return false;
}

struct tm FileChecker::get_date(std::string line, struct tm &date) {
	std::string error = "";
	if ((line[4] != '-' && line[7] != '-') || line.length() != 10)
		error = "date should be in YYYY-MM-DD format: " + line;

	date.tm_year = std::atoi(line.substr(0, 4).c_str());
	date.tm_mon = std::atoi(line.substr(5, 7).c_str());
	date.tm_mday = std::atoi(line.substr(8, 9).c_str());

	if (date.tm_year > CURRENT_YEAR || date.tm_year < BITCOIN_START_YEAR)
		error = "invalid year: " + line;
	if (!(date.tm_mon >= 1 && date.tm_mon <= 12))
		error = "invalid year: " + line;
	if (!(date.tm_mday >= 1 && date.tm_mday <= 31))
		error = "invalid date: " + line;
	if (!error.empty())
		error_exit("Incorrect date format: " + error);

	return date;
}

float FileChecker::get_value(std::string line_val, std::string filename) {
	for (size_t i = 0; i < line_val.length(); i++) {
		if (is_file_char(line_val[i], filename))
			continue;
	}
	float val = atof(line_val.c_str());
	if (val >= FLT_MAX || val < 0)
		error_exit("Incorrect value is provided in " + filename);
	return (val);
}