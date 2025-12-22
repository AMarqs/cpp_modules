#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "CORRECT" << std::endl;
    try
	{
        Bureaucrat a("A", 49);
        std::cout << a << std::endl;
    }
	catch (std::exception &e)
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "HIGH GRADE: 0 < 1" << std::endl;
    try
	{
        Bureaucrat b("B", 0);
    }
	catch (std::exception &e)
	{
        std::cout << "Exception High: " << e.what() << std::endl;
    }
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "LOW GRADE: 151 > 150" << std::endl;
    try
	{
        Bureaucrat c("C", 151);
    }
	catch (std::exception &e)
	{
        std::cout << "Exception Low: " << e.what() << std::endl;
    }
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "INCREMENT GRADE" << std::endl;
    try
	{
        Bureaucrat d("D", 2);
        std::cout << d << std::endl;
		std::cout << "Increment 1: " << std::endl;
        d.incrementGrade();
        std::cout << d << std::endl;
		std::cout << "Increment 2: " << std::endl;
        d.incrementGrade();
    }
	catch (std::exception &e)
	{
        std::cout << "Exception High Increment: " << e.what() << std::endl;
    }
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "DECREMENT GRADE" << std::endl;
    try
	{
        Bureaucrat e("E", 149);
        std::cout << e << std::endl;
		std::cout << "Decrement 1: " << std::endl;
        e.decrementGrade();
        std::cout << e << std::endl;
		std::cout << "Decrement 2: " << std::endl;
        e.decrementGrade();
    }
	catch (std::exception &e)
	{
        std::cout << "Exception Low Decrement: " << e.what() << std::endl;
    }
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "COPY CONSTRUCTOR & ASSIGMENT OPERATOR" << std::endl;
    try
	{
        Bureaucrat f("F", 42);
        Bureaucrat g = f;
        Bureaucrat h("H", 100);
        h = g;
        std::cout << "Copy: " << g << std::endl;
        std::cout << "Assigned: " << h << std::endl;
    }
	catch (std::exception &e)
	{
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}