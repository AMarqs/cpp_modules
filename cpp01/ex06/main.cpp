#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    
    if (argc != 2)
        return 1;

    std::string input = argv[1];
    harl.complain(input);
    
	// std::cout << "DEBUG LEVEL -> ";
	// harl.complain("DEBUG");

	// std::cout << std::endl << "INFO LEVEL -> ";
	// harl.complain("INFO");

	// std::cout << std::endl << "WARNING LEVEL -> ";
	// harl.complain("WARNING");

	// std::cout << std::endl << "ERROR LEVEL -> ";
	// harl.complain("ERROR");

	// std::cout << std::endl << "WRONG LEVEL -> ";
	// harl.complain("wefgwtrbws");

    return 0;
}