#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "---------- FORM CREATION ----------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm shrubbery("S");
        RobotomyRequestForm robotomy("R");
        PresidentialPardonForm pardon("P");
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
    } 
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << "---------- FORM SIGNING ----------" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm shrubbery("S1");
        RobotomyRequestForm robotomy("R1");
        PresidentialPardonForm pardon("P1");
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "A1 (GRADE 1) - CAN SIGN EVERYTHING" << std::endl;
        Bureaucrat a("A1", 1);
        a.signForm(shrubbery);
        a.signForm(robotomy);
        a.signForm(pardon);
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "B1 (GRADE 150) - CAN'T SIGN" << std::endl;
        Bureaucrat b("B1", 150);
        b.signForm(shrubbery);
        b.signForm(robotomy);
        b.signForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
    std::cout << "---------- EXECUTION ----------" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm shrubbery("S2");
        RobotomyRequestForm robotomy("R2");
        PresidentialPardonForm pardon("P2");
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "A2 (GRADE 1) - CAN EXECUTE EVERYTHING" << std::endl;
        Bureaucrat a("A2", 1);
        a.signForm(shrubbery);
        a.signForm(robotomy);
        a.signForm(pardon);
        a.executeForm(shrubbery);
        a.executeForm(robotomy);
        a.executeForm(pardon);
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "B2 (GRADE 150) - CAN'T EXECUTE" << std::endl;
        Bureaucrat b("B2", 150);
        b.executeForm(shrubbery);
        b.executeForm(robotomy);
        b.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "---------- EXECUTE UNSIGNED FORM ----------" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm shrubbery("unsigned_form");
        Bureaucrat a("A3", 1);
        std::cout << "Trying to execute unsigned form:" << std::endl;
        a.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
	std::cout << "--- COPY CONSTRUCTOR & ASSIGMENT OPERATOR ---" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
    try
    {
        ShrubberyCreationForm f1("Form_1");
        Bureaucrat signer("Signer", 100);  
        signer.signForm(f1);
        std::cout << "Form_1: " << f1 << std::endl;

        ShrubberyCreationForm copy(f1);
        std::cout << "Copy: " << copy << std::endl;
        
        ShrubberyCreationForm assigned("Form_1");
        assigned = f1;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}