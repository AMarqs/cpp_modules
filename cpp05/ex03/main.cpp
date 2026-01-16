#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "---------- INTERN MAKEFORM TEST ----------" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "----- CORRECT FORMS -----" << std::endl;
	Intern intern;
	AForm* forms[3];
	forms[0] = intern.makeForm("shrubbery creation", "shrubbery_target");
	forms[1] = intern.makeForm("robotomy request", "robotomy_target");
	forms[2] = intern.makeForm("presidential pardon", "presidential_target");
	std::cout << "Forms created:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] != NULL)
		{
			std::cout << *forms[i] << std::endl;
		}
	}
	std::cout << "Forms deleted:" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] != NULL)
		{
			delete forms[i];
		}
	}
	std::cout << "----- INVALID FORM -----" << std::endl;
	AForm* invalid = intern.makeForm("invalid form", "target");
	if (invalid == NULL)
	{
		std::cout << "The form returned NULL" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "--- COPY CONSTRUCTOR & ASSIGMENT OPERATOR ---" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	Intern intern1;
	AForm* original_form = intern1.makeForm("robotomy request", "original_target");
	std::cout << "----- COPY FORMS -----" << std::endl;
	Intern intern2(intern1);
	AForm* copy_form = intern2.makeForm("presidential pardon", "copy_arget");
	if (copy_form != NULL)
	{
		std::cout << "Copy form: " << *copy_form << std::endl;
		delete copy_form;
	}
	std::cout << "----- ASSIGNED FORM -----" << std::endl;
	Intern intern3;
	intern3 = intern1;
	AForm* assigned_form = intern3.makeForm("shrubbery creation", "assigned_target");
	if (original_form != NULL && assigned_form != NULL)
	{
		std::cout << "Original form: " << *original_form << std::endl;
		std::cout << "Assigned form: " << *assigned_form << std::endl;
		delete original_form;
		delete assigned_form;
	}
	return 0;
}