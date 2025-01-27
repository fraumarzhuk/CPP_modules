#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
	const std::string _name;
	const int _grade_to_sign;
	const int _grade_to_execute;
	bool _is_signed;
public:

	AForm(std::string name="Default form", int grade_to_sign=20, int grade_to_execute=50);
	AForm(const AForm &other);
	AForm &operator= (const AForm &other);
	virtual ~AForm();
	/*setters*/
	// void setIsSigned(bool is_signed);

	/*getters*/
	const std::string &getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getIsSigned() const;

	/*members*/
	void beSigned(const Bureaucrat &buro);
	virtual void execute(const Bureaucrat &executor) const = 0;

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
		class AFormAlreadySignedException: public std::exception
	{
		public:
			const char* what() const throw() { return "Form has already been signed"; }
	};

};

std::ostream & operator << (std::ostream &out, const AForm &form);

#endif
