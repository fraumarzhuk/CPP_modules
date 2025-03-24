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
	if (isdigit(c) || c == '-' || c == '.' || c == ',')
		return true;
	error_exit("Incorrect format of the " + filename + " file. Found char: " + c);
	return false;
}
// void FileChecker::contents_parse(std::string type) {

// }
//first line fort database and for input check, then pass to parsing function