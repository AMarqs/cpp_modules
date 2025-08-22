#include "Harl.hpp"
#include <iostream>

int main()
{
	Harl harl;

	std::cout << "Debug level: ";
	harl.complain("DEBUG");

	std::cout << "Info level: ";
	harl.complain("INFO");

	std::cout << "Warning level: ";
	harl.complain("WARNING");

	std::cout << "Error level: ";
	harl.complain("ERROR");

	std::cout << "Worng level: ";
	harl.complain("wefgwtrbws");

	return 0;
}