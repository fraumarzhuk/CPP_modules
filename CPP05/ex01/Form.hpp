#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	const std::string _name;
	const int _grade_to_sign;
	const int _grade_to_execute;
	bool _is_signed;
public:

	Form(std::string name="Default form", int grade_to_sign=20, int grade_to_execute=50);
	Form(const Form &other);
	Form &operator= (const Form &other);
	~Form();
	/*setters*/
	// void setIsSigned(bool is_signed);

	/*getters*/
	const std::string &getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const;

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

std::ostream & operator << (std::ostream &out, const Form &form);

#endif
