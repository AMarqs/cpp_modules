#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
{ std::cout << "Default constructor called" << std::endl; }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout << "Copy assignment operator called" << std::endl; 
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{ std::cout << "Default destructor called" << std::endl; }

std::string Bureaucrat::getName() const
{
	//std::cout << "getName member function called" << std::endl;
	return _name;
}

int Bureaucrat::getGrade() const
{
	//std::cout << "getGrade member function called" << std::endl;
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}