
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
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
	{
		throw GradeTooHighException();
		return ;
	}
	else
	{
		_grade--;
		return ;
	}
	std::cout << LIME200 << _name << "Grade incremented to: " << _grade << RESET << std::endl;
}

void Bureaucrat::decrementGrade()
{
	std::cout << "cur grade: " << this->getGrade() << std::endl;
	if ((_grade + 1) > 150)
	{
		std::cout << "here" << std::endl;
		throw GradeTooLowException();
		return ;
	}
	else
	{
		_grade++;
		return ;
	}
	std::cout << PINK300 << _name << "Grade decremented to: " << _grade << RESET << std::endl;
}

std::ostream &operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade is " << bureaucrat.getGrade() << std::endl;
	return (out);
}