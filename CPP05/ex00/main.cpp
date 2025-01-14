#include "Bureaucrat.hpp"



int main()
{

	Bureaucrat stepan("Stepan", 1);
	Bureaucrat oleg("Oleg", 150);
	try
	{
		oleg.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< e.what() << std::endl;
	}

	try
	{
		stepan.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	std::cout << stepan.getGrade() << std::endl;
	std::cout << oleg.getGrade() << std::endl;
}