#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "colors.hpp"
#include "AForm.hpp"


class AForm;
//exception classes dont have to be designed in ocf
class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(std::string name="random clerk", int grade=145);
	~Bureaucrat();

	/*getters*/
	const std::string &getName() const;
	int getGrade() const;

	/*members*/
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);
	void executeForm(AForm const & form);

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

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
