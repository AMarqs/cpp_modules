#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
private:
	static const std::string _formNames[3];
	AForm* createShrubbery(const std::string& target) const;
	AForm* createRobotomy(const std::string& target) const;
	AForm* createPresidential(const std::string& target) const;

public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& copy);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& formTarget) const;
};

#endif