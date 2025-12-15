#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { 
	// std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value) : _value(value << _fracBits) {
	// std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fracBits))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value;
	return *this;
}

// GETTER AND SETTER

int Fixed::getRawBits( void ) const { return _value; }
void Fixed::setRawBits( int const raw ) { _value = raw; }

// CONVERSION TO FLOAT AND INT

float	Fixed::toFloat( void ) const { return (float)(_value) / (1 << _fracBits); }
int		Fixed::toInt( void ) const { return _value >> _fracBits; }

// OVERLOAD

// Insertion <<

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

// Comparison Operators

bool Fixed::operator>(const Fixed& other) const { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

// Arithmetic operators

Fixed Fixed::operator+(const Fixed& other) const 
{
	Fixed result;
	result._value = _value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const 
{
	Fixed result;
	result._value = _value - other._value;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const 
{
	Fixed result;
	result._value = (_value * other._value) >> _fracBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const 
{
	if (other._value == 0)
	{
		std::cout << "Error: Division by 0" << std::endl;
		return 0;
	}
	Fixed result;
	result._value = (_value << _fracBits) / other._value;
	return result;
}

// Increment-Decrement

Fixed& Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed prev = *this;
	_value++;
	return prev;
}

Fixed& Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed prev = *this;
	_value--;
	return prev;
}

// OVERLOAD FUNCTIONS MIN-MAX

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }
