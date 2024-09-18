#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream> 
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contact_list[8];
	public:
		PhoneBook(void) = default;
		~PhoneBook(void) = default;
};

#endif

