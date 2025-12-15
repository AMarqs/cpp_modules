#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
// En el enunciado pone que sean float y en la hoja de evaluacion Fixed
// Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}
Point& Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}
Point::~Point() {}

const Fixed Point::getX( void ) const { return _x; }
const Fixed Point::getY( void ) const { return _y; }