#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void)
{
	exited = false;
	counter = 0;
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
	Contact cur_contact = this->_contact_list[counter % 9];
	std::cout << CYAN << "ADDING NEW CONTACT..." << RESET << std::endl;
	std::cout << "Enter first name:" << std::endl;
	std::cin >> cur_contact.first_name;
	std::cout << "Enter last name:" << std::endl;
	std::cin >> cur_contact.last_name;
	std::cout << "Enter nickname:" << std::endl;
	std::cin >> cur_contact.nickname;
	std::cout << "Enter phone_number:" << std::endl;
	std::cin >> cur_contact.phone_number;
	std::cout << "Enter darkest secret:" << std::endl;
	std::cin >> cur_contact.darkest_secret;
	std::cout << BLUE << "CONTACT SAVED SUCCESSFULLY!" << RESET << std::endl;
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