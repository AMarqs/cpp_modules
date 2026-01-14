#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("Default target")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::string filename = this->_target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (file.is_open())
    {
        file << std::endl;
        file << "    /\\         /\\" << std::endl;
        file << "   /  \\       /  \\" << std::endl;
        file << "  /    \\     /    \\" << std::endl;
        file << " /      \\   /      \\" << std::endl;
        file << "/________\\ /________\\" << std::endl;
        file << "    ||          ||" << std::endl;
        file << "    ||          ||" << std::endl;
        
        file.close();
        std::cout << "ASCII trees created in " << filename << std::endl;
    }
    else
    {
        std::cout << "Error creating file " << filename << std::endl;
    }
}
