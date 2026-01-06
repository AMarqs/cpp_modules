#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& copy);
		Form& operator=(const Form& copy);
		~Form();

		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif