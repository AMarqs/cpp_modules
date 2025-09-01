#include <iostream>
#include "Point.hpp"

Fixed area(Point A, Point B, Point C)
{
	Fixed	xA = A.getX(), yA = A.getY();
	Fixed	xB = B.getX(), yB = B.getY();
	Fixed	xC = C.getX(), yC = C.getY();

	Fixed area = (xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB)) / 2;
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	areaABC = area(a, b, c);
	Fixed	areaPAB = area(point, a, b);
	Fixed	areaPBC = area(point, b, c);
	Fixed	areaPCA = area(point, c, a);

	if (areaABC == Fixed(0))
		return false;
	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPCA == Fixed(0)) // Border point
		return false;
	if (areaABC != (areaPAB + areaPBC + areaPCA))
		return false;
	return true;
}