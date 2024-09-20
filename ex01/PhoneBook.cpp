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
		// std::cout << "Enter " << value << ":" << std::endl;
		// std::getline(std::cin, placeholder);
		// if (placeholder.empty() || !is_valid_input(placeholder, 1)) //add check for spaces(chars and nums?)
		// 	std::cout << RED <<"Fields can't be empty!"<< RESET << std::endl;
		// else
		// 	break ;
		std::cout << "Enter " << value << ":" << std::endl;
		std::getline(std::cin, placeholder);
		if (value == "phone number" && !is_valid_input(placeholder, 2))
			std::cout << RED <<"Number shouldn't contain letters!"<< RESET << std::endl;
		else if (placeholder.empty() || !is_valid_input(placeholder, 1))
			std::cout << RED <<"Field can't be empty or contain numbers!"<< RESET << std::endl;
		else
			break ;
	}
}

void PhoneBook::search_contact(void)
{
	std::string index;
	int i = 0;
	int got_input = 0;
	std::stringstream ss;
	//display_contacts
	std::cout << CYAN << "CURRENT CONTACTS:" << RESET << std::endl;
	while (i < 8)
	{
		std::cout << "        " << _contact_list[i].index << " | ";
		display_in_column(_contact_list[i].first_name);
		display_in_column(_contact_list[i].last_name);
		display_in_column(_contact_list[i].nickname);
		std::cout << std::endl;
		i++;
	}
	//display detailed
	while (!got_input)
	{
		std::cout << "Enter the index of the contact:" << std::endl;
		std::getline(std::cin, index);
    	ss << index;
   	 	ss >> i;  
		if (i >= 0 && i <= 7)
			got_input = 1;
		else
			std::cout << RED <<"Incorrect value. Please try again." <<  RESET << std::endl;
	}
	std::cout << _contact_list[i].first_name << std::endl;
	std::cout << _contact_list[i].last_name << std::endl;
	std::cout << _contact_list[i].nickname << std::endl;
	std::cout << _contact_list[i].phone_number << std::endl;
	std::cout << _contact_list[i].darkest_secret << std::endl;

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

int PhoneBook::is_valid_input(std::string input, int option)
{
	int found = 0;
	int i = 0;
	while (input[i])
	{
		if (isalpha(input[i]) || isdigit(input[i]))
			found = 1;
		i++;
	}
	if (option == 0)
		return (found);
	else if (option == 1) //is only alphas
	{
		while (input[i])
		{
			if (!isalpha(input[i]) && input[i] != ' ')
				return (0);
			i++; 
		}
	}
	else if (option == 2) // is only numericals
	{
		while (input[i])
		{
			if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '+')
				return (0);
			i++; 
		}
	}
	return (found);
}