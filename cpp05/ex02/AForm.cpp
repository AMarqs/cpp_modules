#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150)
{ std::cout << "Form default constructor called" << std::endl; }

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "Form constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& copy)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_signed = copy._signed;
    }
    return *this;
}

AForm::~AForm()
{ std::cout << "Form destructor called" << std::endl; }

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
    return this->_signed;
}

int AForm::getSignGrade() const
{
    return this->_sign_grade;
}

int AForm::getExecGrade() const
{
    return this->_exec_grade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_sign_grade)
        throw GradeTooLowException();
    this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	std::string sign = "";
	if (form.getSigned() == true)
		sign = "yes";
	else if (form.getSigned() == false)
		sign = "no";
    out << "Form " << form.getName() << ", signed: " << sign << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ".";
    return out;
}