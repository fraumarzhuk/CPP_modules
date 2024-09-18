#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream> 
#include "PhoneBook.hpp"

class Contact
{
	private:
		int _delete_later;
	public:
		Contact(void) = default;
		~Contact(void) = default;
		int index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

};

#endif