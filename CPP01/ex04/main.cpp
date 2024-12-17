#include <iostream>
#include <fstream>
#include <string>
#include "colors.hpp"

int main(int argc, char **argv){
	if (argc != 4)
		std::cerr << AMBER200 << "Incorrect amount of arguments!" << RESET << std::endl, exit(1);
	std::string infile_name = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	std::ifstream infile(infile_name);
	if (!infile)
		std::cerr << AMBER200 << "Error opening infile" << RESET << std::endl, exit (1);
	std::ofstream outfile(infile_name + ".replace");
	if (!outfile)
		std::cerr << AMBER200 << "Error creating outfile" << RESET << std::endl, exit (1);
	std::string cur_line;
	while (std::getline(infile, cur_line)) {
		int pos = 0;
		while ((pos = cur_line.find(str1, pos)) != -1) {
			cur_line.erase(pos, str1.length());
			cur_line.insert(pos, str2);
			pos += str2.length();
		}
		outfile << cur_line << std::endl;
	}
}