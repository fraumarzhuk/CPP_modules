
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	
	std::cout << PINK600 << "Bureaucrat Constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << PINK600 << "Bureaucrat Destructor called" << RESET << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if ((_grade - 1) < 1)
		throw GradeTooHighException();
	else
		_grade--;
	std::cout << LIME200 << _name << "Grade incremented to: " << _grade << RESET << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	else
		_grade++;
	std::cout << PINK300 << _name << "Grade decremented to: " << _grade << RESET << std::endl;
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade is " << bureaucrat.getGrade() << std::endl;
	return (out);
}

void Bureaucrat::signForm(Form &form){
	try {
		form.beSigned( *this );
		std::cout << GREEN500 << _name << " signed " << form.getName() << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << PINK600 << _name << " couldn't sign " << form.getName() << " because " << PINK300 << e.what() << RESET << std::endl;
	}
}
