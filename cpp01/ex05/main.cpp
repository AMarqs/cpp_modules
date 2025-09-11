#include <iostream>
#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "--- DEBUG LEVEL ---" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << "--- INFO LEVEL ---" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << "--- WARNING LEVEL ---" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "--- ERROR LEVEL ---" << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl << "--- WRONG LEVEL ---" << std::endl;
	harl.complain("wefgwtrbws");

	return 0;
}