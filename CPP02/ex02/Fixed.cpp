
#include "Fixed.hpp"

Fixed::Fixed(): _fp_number_val(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){
	this->_fp_number_val = num << this->_fract_bits;
	std::cout << "Const int constructor called" << std::endl;
}

Fixed::Fixed(const float num) {
	std::cout << "Const float constructor called" << std::endl;
	_fp_number_val = (int)roundf(num * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		_fp_number_val = other.getRawBits();
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

float Fixed::toFloat(void) const{
	float f_num = (float)this->_fp_number_val / (1 << _fract_bits);
	return (f_num);
}
int Fixed::toInt(void) const{
	int i_num = this->_fp_number_val >> _fract_bits;
	return (i_num);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
std::ostream &operator<<(std::ostream& ostream, const Fixed& fixed){
	ostream << fixed.toFloat();
	return (ostream);
}
bool Fixed::operator>(const Fixed &other) const{
	return (this->_fp_number_val > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const{
	return (this->_fp_number_val < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const{
	return (this->_fp_number_val >+ other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const{
	return (this->_fp_number_val <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const{
	return (this->_fp_number_val == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const{
	return (this->_fp_number_val != other.getRawBits());
}