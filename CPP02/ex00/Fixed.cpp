#include "Fixed.hpp"

Fixed::Fixed(): _fp_number_val(0){
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		_fp_number_val = other._fp_number_val;
	}
	return (*this);
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fp_number_val);
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits function called" << std::endl;
	this->_fp_number_val = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}