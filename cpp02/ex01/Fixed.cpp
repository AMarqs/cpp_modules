#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int value) : _value(value << _fracBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fracBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

int Fixed::getRawBits(void) const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)(_value) / (1 << _fracBits);
}

int		Fixed::toInt(void) const
{
	return _value >> _fracBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}