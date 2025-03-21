#include "BitcoinExchange.hpp"
#include <map>
#include "colors.hpp"
#include <iostream>

//TODO:
//1. arguments check
	//1.1 check format, file passed, access rights
	//1.2 check that file can be open and not empty
//2. contents of file check
	//first line check "date | value " strcmp
	//1. format check
		//2.1.1 contains 1 pipe, save in multimap: date + value
			//saving date in string. checks that position 4 is dash and position 7 is dash
			// function, converting into array of int and checking that month and date are in correct range
		//2.1.2 checking that value is from 0 and 1000, int or float

//3. same(almost) checks for the database? //create a file checker
//4. print function with multiplication

int main(int argc, char **argv) {
	if (argc != 2){
		std::cerr << RED500 <<"Incorrect amount of parameters" << RESET << std::endl;
		return (1);
	}
	FileChecker::file_check(argv[1]);
}