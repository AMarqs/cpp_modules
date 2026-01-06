#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150)
{ std::cout << "Form default constructor called" << std::endl; }

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "Form constructor called" << std::endl;
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    else if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& copy)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_signed = copy._signed;
    }
    return *this;
}

Form::~Form()
{ std::cout << "Form destructor called" << std::endl; }

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
    return this->_signed;
}

int Form::getSignGrade() const
{
    return this->_sign_grade;
}

int Form::getExecGrade() const
{
    return this->_exec_grade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_sign_grade)
        throw GradeTooLowException();
    this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::string sign = "";
	if (form.getSigned() == true)
		sign = "yes";
	else if (form.getSigned() == false)
		sign = "no";
    out << "Form " << form.getName() << ", signed: " << sign << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << ".";
    return out;
}