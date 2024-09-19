#include "PhoneBook.hpp"
#include <iostream> 

int main()
{
	PhoneBook my_phone_book;
	std::string input_cmd;

	std::cout << "Welcome to the PhoneBook!" << std::endl;
	std::cout << "Availiable cmds: ADD, SEARCH, EXIT" << std::endl;
	while (!my_phone_book.exited)
	{
		std::cout << "Enter your command: " << std::endl;
		std::getline(std::cin, input_cmd);
		if (!input_cmd.compare("EXIT"))
			my_phone_book.exited = true;
		else if (!input_cmd.compare("ADD"))
		{
			my_phone_book.add_contact();
			//my_phone_book.counter++;
		}
		else if (!input_cmd. compare("SEARCH"))
			// std::cout << "Lets search some contacts" << std::endl;
			my_phone_book.search_contact();
	}
	return (0);
}