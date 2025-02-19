#include "Bureaucrat.hpp"



int main()
{

	Bureaucrat stepan("Stepan", 1);
	Bureaucrat oleg("Oleg", 150);
	std::cout << "Creating classes with incorrect values:" << std::endl;
	try {
		Bureaucrat chris("Chris", 160);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	try {
		Bureaucrat random("Random", 0);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "Trying increment and decrement with max and min grades: " << std::endl;
	try {
		oleg.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr<< e.what() << std::endl;
	}


	try {
		stepan.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr<< e.what() << std::endl;
	}
	std::cout << "Stepan's grade: "<< stepan.getGrade() << std::endl;
	std::cout << " Oleg's grade: " << oleg.getGrade() << std::endl;

	std::cout << "Trying increment and decrement with correct grades: " << std::endl;
	try {
		oleg.incrementGrade();
		stepan.decrementGrade();
	}
	catch (std::exception &e) {
		std::cerr<< e.what() << std::endl;
	}

}