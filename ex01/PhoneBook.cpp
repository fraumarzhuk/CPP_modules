#include "PhoneBook.hpp"
#include <cstdlib> 
#include <sstream>


PhoneBook::PhoneBook(void)
{
	exited = false;
	counter = 0;
	create_list();
}
PhoneBook::~PhoneBook(void)
{
	return ;
}
void PhoneBook::create_list(void){
	for (int i = 0; i <= 8; i++)
		_contact_list[i].index = i;
}

void PhoneBook::add_contact(void) 
{
	Contact& cur_contact = _contact_list[counter % 8];
	cur_contact.save_contact_values();
	counter++;
}

void PhoneBook::search_contact(void)
{
	std::string index;
	int i = 0;
	int got_input = 0;
	//display_contacts
	std::cout << CYAN << "CURRENT CONTACTS:" << RESET << std::endl;
	while (i < 8)
	{
		if (_contact_list[i].contact_filled)
			_contact_list[i].display_contact_values(false);
		i++;
	}
	//display detailed
	while (!got_input)
	{
		std::cout << "Enter the index of the contact:" << std::endl;
		if (!std::getline(std::cin, index) || !index.compare("EXIT"))
			exit(1);
		i = atoi(index.c_str());
		if (_contact_list[i].is_valid_input(index, NUM) && i >= 0 && i <= 7)
			got_input = 1;
		else if (!_contact_list[i].contact_filled)
			std::cout << "This contact is empty." << std::endl << std::endl;
		else
			std::cout << RED <<"Incorrect value: " << i << " Please try again." <<  RESET << std::endl;
	}
	_contact_list[i].display_contact_values(true);
}

