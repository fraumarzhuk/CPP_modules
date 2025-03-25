#include "FileChecker.hpp"

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
	exit(1);
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

Date FileChecker::get_date(std::string line, Date &date) {
	std::string error = "";
	if ((line[4] != '-' && line[7] != '-') || line.length() != 10)
		error = "date should be in YYYY-MM-DD format: " + line;

	date.year = std::atoi(line.substr(0, 4).c_str());
	date.month = std::atoi(line.substr(5, 7).c_str());
	date.day = std::atoi(line.substr(8, 9).c_str());
	//std::cout << "date: " << date[0] << "-" << date[1] << "-"  << date.day << std::endl;
	if (date.year > CURRENT_YEAR || date.year < BITCOIN_START_YEAR)
		error = "invalid year: " + line;
	if (!(date.month >= 1 && date.month <= 12))
		error = "invalid year: " + line;
	if (!(date.day >= 1 && date.day <= 31))
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