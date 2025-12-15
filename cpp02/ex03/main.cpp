#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);
    
    Point p1(2.0f, 1.0f);
    std::cout << "Inside point: " << bsp(a,b,c,p1) << std::endl;
    
    Point p2(5.0f, 1.0f);
    std::cout << "Outside point: " << bsp(a,b,c,p2) << std::endl;

    Point p3(0.0f, 0.0f);
    std::cout << "Point on vertex: " << bsp(a,b,c,p3) << std::endl;

    Point p4(2.0f, 0.0f);
    std::cout << "Point on border: " << bsp(a,b,c,p4) << std::endl;

	Point a0(0.0f, 0.0f);
    Point b0(0.0f, 0.0f);
    Point c0(0.0f, 0.0f);
	Point p5(2.0f, 1.0f);
    std::cout << "Area 0: " << bsp(a0,b0,c0,p5) << std::endl;

	return 0;
}