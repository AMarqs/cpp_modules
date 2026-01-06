#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "----------------------------------" << std::endl;
    std::cout << "---------- FORM CREATION ---------" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "CORRECT" << std::endl;
	try
	{
		Form a("A", 50, 25);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "HIGH GRADE" << std::endl;
	try
	{
		Form b("B", 0, 25);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception High: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "LOW GRADE" << std::endl;
	try
	{
		Form c("C", 151, 25);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Low: " << e.what() << std::endl;
	}
    std::cout << "---------------------------------" << std::endl;
    std::cout << "---------- FORM SIGNING ---------" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    Form form("Form", 50, 25);
    std::cout << "CORRECT" << std::endl;
	try
	{
		Bureaucrat b1("Bureaucrat_1", 30);
        std::cout << "Before signing: " << form << std::endl;
        b1.signForm(form);
        std::cout << "After signing: " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "LOW SIGNING GRADE" << std::endl;
	try
	{
		Bureaucrat b2("Bureaucrat_2", 100);
        b2.signForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception High: " << e.what() << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "--- COPY CONSTRUCTOR & ASSIGMENT OPERATOR ---" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	try
	{
		Form f1("Form_1", 100, 75);
        Bureaucrat signer("Signer", 50);
        signer.signForm(f1);
        std::cout << "Form_1: " << f1 << std::endl;

        Form copy(f1);
        std::cout << "Copy: " << copy << std::endl;

        Form assigned("Form_2", 150, 150);
        assigned = f1;
        std::cout << "Assigned: " << assigned << std::endl;
    }
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
    return 0;
}