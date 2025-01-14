#include "Bureaucrat.hpp"



int main()
{

	try
	{
		Bureaucrat oleg("Oleg", 150);
		oleg.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	try
	{
		Bureaucrat stepan("Stepan", 1);
		stepan.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr<< e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr<< e.what() << std::endl;
	}
}