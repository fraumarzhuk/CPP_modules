#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "colors.hpp"
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const int grade_to_sign;
	const int grade_to_execute;
	bool _is_signed;
public:

	Form();
	Form(const Form &other);
	Form &operator= (const Form &other);
	~Form();

	/*setters*/

	/*getters*/

	/*members*/
	void beSigned(const Bureaucrat &buro);

	/*exceptions*/
	class GradeTooHighException: public std::exception
	{
		public:
			const char* what() const throw() { return "Grade is too high!"; }
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char* what() const throw() { return "Grade is too low!"; }
	};


};
#endif
