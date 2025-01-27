#include "Form.hpp"

Form::Form(std::string name, int grade_to_sign, int grade_to_execute): _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{	
	std::cout << CYAN300 << "Form Constructor called" << RESET << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute), _is_signed(other._is_signed)
{
	std::cout << CYAN300 << " Form Copy constructor called" << RESET << std::endl;
	*this = other;
}

Form &Form::operator = (const Form &other)
{
	std::cout << CYAN300 <<  "Form Copy assignment operator called." << RESET << std::endl;
	if (this != &other)
			std::cout << PINK300 << "Cannot assign the form sry" <<  RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << CYAN800 <<" Form Destructor called" << RESET << std::endl;
}


const std::string &Form::getName() const
{
	return _name;
}

int Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

void Form::beSigned(const Bureaucrat &buro)
{
	if (_is_signed)
		throw Form::FormAlreadySignedException();
	else if (buro.getGrade() > _grade_to_sign )
		throw Form::GradeTooLowException();
	// else if ( buro.getGrade() < _grade_to_sign )
	// 	throw Form::GradeTooHighException();
	_is_signed = true;

}

std::ostream&	operator<<( std::ostream& out, const Form& form ) {
	out << form.getName() << ( form.getIsSigned() ? ", signed" : ", not signed yet" ) << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return out;
}
