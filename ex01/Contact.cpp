#include "Contact.hpp"

Contact::Contact(void)
{
	this->contact_filled = false;
	return ;
}

Contact::~Contact(void)
{
	return ;
}
void Contact::display_contact_values(bool index_given)
{
	if (index_given)
	{
		std::cout << std::endl << GREEN << "^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V" << RESET << std::endl << std::endl;
		std::cout << "First name: " << this->_first_name << std::endl;
		std::cout << "Last name: " << this->_last_name << std::endl;
		std::cout << "Nickname: " << this->_nickname << std::endl;
		std::cout << "Phone number: " << this->_phone_number << std::endl;
		std::cout << "Darkest secret: " << this->_darkest_secret << std::endl;
		std::cout << std::endl << GREEN << "^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V" << RESET << std::endl << std ::endl;
	}
	else
	{
		std::cout <<  std::setw(8)  << this->index << " | ";
		display_in_column(this->_first_name);
		display_in_column(this->_last_name);
		display_in_column(this->_nickname);
		std::cout << std::endl;
	}
}

void Contact::save_contact_values(void)
{
	std::cout << CYAN << "ADDING NEW CONTACT..." << RESET << std::endl;
	this->save_input("first name", this->_first_name);
	this->save_input("last name", this->_last_name);
	this->save_input("nickname", this->_nickname);
	this->save_input("phone number", this->_phone_number);
	this->save_input("darkest secret", this->_darkest_secret);
	std::cout << BLUE << "CONTACT SAVED SUCCESSFULLY!" << RESET << std::endl;
	this->contact_filled = true;
}

void Contact::save_input(std::string value, std::string& placeholder)
{
    while (true)
    {
        std::cout << "Enter " << value << ":" << std::endl;
        if (!std::getline(std::cin, placeholder) || !placeholder.compare("EXIT"))
			exit(1);
        if (placeholder.empty() || !is_valid_input(placeholder, 0))
            std::cout << RED << "Field can't be empty!" << RESET << std::endl;
        else if (value == "phone number" && !is_valid_input(placeholder, 2))
                std::cout << RED << "Number shouldn't contain letters!" << RESET << std::endl;
        else if ((value == "first name" || value == "last name") && !is_valid_input(placeholder, ALPHA))
                std::cout << RED << "Field can't contain numbers!" << RESET << std::endl;
		else
			break ;
    }
}

int Contact::is_valid_input(std::string input, int option)
{
	int found = 0;
	int i = 0;
	while (input[i])
	{
		if (isalpha(input[i]) || isdigit(input[i]))
			found = 1;
		i++;
	}
	if (option == NOT_EMPTY)
		return (found);
	i = 0;
	if (option == ALPHA)
	{
		while (input[i])
		{
			if (!isalpha(input[i]) && input[i] != '-')
				return (0);
			i++;
		}
	}
	else if (option == NUM)
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

void Contact::display_in_column(std::string field_name)
{
	if (field_name.length() > 8)
	{
		field_name = field_name.substr(0, 7);
		field_name += '.';
	}
	std::cout << std::setw(8) << field_name << " | ";
}
