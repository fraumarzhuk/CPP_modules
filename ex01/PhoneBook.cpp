#include "PhoneBook.hpp"


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
	std::cout << CYAN << "ADDING NEW CONTACT..." << RESET << std::endl;
	save_input("first name", cur_contact.first_name);
	save_input("last name", cur_contact.last_name);
	save_input("nickname", cur_contact.nickname);
	save_input("phone number", cur_contact.phone_number);
	save_input("darkest secret", cur_contact.darkest_secret);
	std::cout << BLUE << "CONTACT SAVED SUCCESSFULLY!" << RESET << std::endl;
	counter++;
}
void PhoneBook::save_input(std::string value, std::string& placeholder)
{
	while (1)
	{
		std::cout << "Enter " << value << ":" << std::endl;
		std::getline(std::cin, placeholder);
		if (placeholder.empty()) //add check for spaces(chars and nums?)
			std::cout << RED <<"Fields can't be empty!"<< RESET << std::endl;
		else
			break ;
	}
}

void PhoneBook::search_contact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	int i = 0;
	//display_contacts
	std::cout << CYAN << "CURRENT CONTACTS:" << RESET << std::endl;
	while (i < 8)
	{
		std::cout << "        " << _contact_list[i].index << " | ";
		first_name = _contact_list[i].first_name;
		display_in_column(first_name);
		last_name = _contact_list[i].last_name;
		display_in_column(last_name);
		nickname = _contact_list[i].nickname;
		display_in_column(nickname);
		std::cout << std::endl;
		i++;
	}
	

}
void PhoneBook::display_in_column(std::string field_name)
{
	int chars_left = 0;
	if (field_name.length() > 8)
	{
		field_name = field_name.substr(0, 7);
		field_name += '.';
	}
	chars_left = 8 - field_name.length();
	while (chars_left-- > 0)
		std::cout << " ";
	std::cout << field_name <<  " | ";
	
}

//add a function to push contacts
	//if more that 8 contacts already, replace the oldest one with the new one)
	//(set a variable for an oldest index)
//function add_contact()
	//asks for prompt one by one
	//The contact fields are: first name, last name, nickname, phone number, and
	//darkest secret. A saved contact can’t have empty fields.
//function search_contact()
	//display weird columns (index, firstname, last_name, nickname)
	//ask for an index
	//if correct index -> display the contact info one line at a time
//function exit
	//quits