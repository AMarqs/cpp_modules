#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a: " << a << std::endl;
	std::cout << "Pre-increment: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "Post-increment: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << "b: " << b << std::endl;

	std::cout << "Minimum: " << Fixed::min( a, b ) << std::endl;
	std::cout << "Maximum: " << Fixed::max( a, b ) << std::endl;

	std::cout << "Add: " << a + b << std::endl;
	std::cout << "Substraction: " << a - b << std::endl;
	std::cout << "Multiplication: " << a * b << std::endl;
	std::cout << "Division: " << a / b << std::endl;

	return 0;
}