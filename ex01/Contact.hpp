#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cstdlib>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

#define ALPHA 1
#define NUM 2
#define NOT_EMPTY 0

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		void save_input(std::string value, std::string& placeholder);
		int is_valid_input(std::string input, int option);
		void save_contact_values(void);
		void display_contact_values(bool index_given);
		void display_in_column(std::string field_name);
		int contact_filled;
		int index;

};

#endif