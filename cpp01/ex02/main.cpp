#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "--- MEMORY ADDRESS ---" << std::endl;
	std::cout << "String: " << &str << std::endl;
	std::cout << "Pointer: " << stringPTR << std::endl;
	std::cout << "Reference: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "--- VALUE ---" << std::endl;
	std::cout << "String: " << str << std::endl;
	std::cout << "Pointer: " << *stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;
}