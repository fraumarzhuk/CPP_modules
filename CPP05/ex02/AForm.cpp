#include "AForm.hpp"

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute): _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _is_signed(false)
{	
	std::cout << CYAN300 << "Form Constructor called" << RESET << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other._name), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute), _is_signed(other._is_signed)
{
	std::cout << CYAN300 << " AForm Copy constructor called" << RESET << std::endl;
	*this = other;
}

AForm &AForm::operator = (const AForm &other)
{
	std::cout << CYAN300 <<  "AForm Copy assignment operator called." << RESET << std::endl;
	if (this != &other)
			std::cout << PINK300 << "Cannot assign the AForm sry" <<  RESET << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << CYAN800 <<" AForm Destructor called" << RESET << std::endl;
}


const std::string &AForm::getName() const
{
	return _name;
}

int AForm::getGradeToSign() const
{
	return _grade_to_sign;
}

int AForm::getGradeToExecute() const
{
	return _grade_to_execute;
}

bool AForm::getIsSigned() const
{
	return _is_signed;
}

void AForm::beSigned(const Bureaucrat &buro)
{
	if (_is_signed)
		throw AForm::AFormAlreadySignedException();
	else if (buro.getGrade() > _grade_to_sign )
		throw AForm::GradeTooLowException();
	_is_signed = true;
	std::cout << LIME300 << "Form succesfully signed" << RESET << std:: endl;

}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_is_signed)
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > _grade_to_execute)
		throw AForm::GradeTooLowException();
	action();
	
}

std::ostream&	operator<<( std::ostream& out, const AForm& form ) {
	out << form.getName() << ( form.getIsSigned() ? ", signed" : ", not signed yet\n" ) << ", grade to sign: " << form.getGradeToSign() << std::endl;
	out << ", grade to execute: " << form.getGradeToExecute();
	return out;
}
