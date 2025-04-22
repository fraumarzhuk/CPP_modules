#include "BitcoinExchange.hpp"
#include <map>
#include "colors.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		FileChecker::error_exit("Incorrect amount of parameters");
		exit(1);
	}
	FileChecker::file_check(argv[1]);
	BitcoinExchange exchanger(argv[1]);
}