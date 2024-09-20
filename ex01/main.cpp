#include "PhoneBook.hpp"
#include <iostream> 
int main()
{
	PhoneBook my_phone_book;
	std::string input_cmd;

	std::cout << MAGENTA << " ☎️ WELCOME TO THE PHONEBOOK! ☎️ " << RESET << std::endl;
	std::cout << BLUE <<"Availiable cmds: ADD, SEARCH, EXIT" << RESET << std::endl;
	while (!my_phone_book.exited)
	{
		std::cout << "Enter your command: " << std::endl;
		if (!std::getline(std::cin, input_cmd))
			exit(1);
		if (!input_cmd.compare("EXIT"))
			my_phone_book.exited = true;
		else if (!input_cmd.compare("ADD"))
		{
			my_phone_book.add_contact();
		}
		else if (!input_cmd. compare("SEARCH"))
			my_phone_book.search_contact();
	}
	return (0);
}