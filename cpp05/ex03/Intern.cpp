#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

const std::string Intern::_formNames[3] = {"shrubbery creation","robotomy request", "presidential pardon"};

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)copy;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::createShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm* (Intern::*forms[3])(const std::string& target) const = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};
	for (int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*forms[i])(target);
		}
	}
	std::cout << "Error: " << formName << " form doesn't exist" << std::endl;
	return NULL;
}