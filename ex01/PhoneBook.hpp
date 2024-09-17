#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <vector>

class PhoneBook
{
	private:
		std::vector< int > arr[8];
		void add_numbers(const PhoneBook& phonebook);
	public:
		PhoneBook() = default;
		~PhoneBook() = default;
};

#endif