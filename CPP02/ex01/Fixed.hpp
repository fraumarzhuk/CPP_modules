#ifndef FIXED_HPP
#define FIXED_HPP
#include "colors.hpp"
#include <iostream>
#include <cmath>

class Fixed{
private:
	int _fp_number_val;
	static const int _fract_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int num);
	Fixed(const float num);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
#endif


// However, one of the truly nice things about floats is that when they overflow, you are conveniently left with +/-inf. These quantities tend to behave as expected: +inf is greater than any other number, -inf is less than any other number, inf+1 equals inf, and so on. This property makes floats useful for checking overflow in integer math as well. You can do a calculation in floating point, then simply compare the result to something like INT_MAX before casting back to integer.