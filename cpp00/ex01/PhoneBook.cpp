#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : total_contacts(0), next_index(0) {}
PhoneBook::~PhoneBook() {};

bool is_number(std::string num)
{
	long unsigned int i = 0;

	if (num.empty())
		return false;

	while (i < num.length())
	{
		if (!isdigit(num[i]))
			return false;
		i++;
	}
	return true;
}

void	PhoneBook::add_contact()
{
	std::string firstName, lastName, nickname, phoneNumber, secret;

	std::cout << "Fill the contact fields" << std::endl;
	std::cout << "First Name (max 10 characters): ";
	std::getline(std::cin, firstName);
	while (firstName.length() > 10)
	{
		std::cout << "Maximum 10 characters for First Name" << std::endl;
		std::cout << "First Name (max 10 characters): ";
		std::getline(std::cin, firstName);
	}
	std::cout << "Last Name (max 10 characters): ";
	std::getline(std::cin, lastName);
	while (lastName.length() > 10)
	{
		std::cout << "Maximum 10 characters for Last Name" << std::endl;
		std::cout << "Last Name (max 10 characters): ";
		std::getline(std::cin, lastName);
	}
	std::cout << "Nickname (max 10 characters): ";
	std::getline(std::cin, nickname);
	while (nickname.length() > 10)
	{
		std::cout << "Maximum 10 characters for Nickname" << std::endl;
		std::cout << "Nickname (max 10 characters): ";
		std::getline(std::cin, nickname);
	}
	std::cout << "Phone Number (max 9 numbers): ";
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.length() > 9 || !is_number(phoneNumber))
	{
		std::cout << "Maximum 9 numbers for Phone Number" << std::endl;
		std::cout << "Phone Number (max 9 numbers): ";
		std::getline(std::cin, phoneNumber);
	}
	std::cout << "Darkest Secret (max 40 characters): ";
	std::getline(std::cin, secret);
	while (secret.length() > 40)
	{
		std::cout << "Maximum 10 characters for Darkest Secret" << std::endl;
		std::cout << "Darkest Secret (max 40 characters): ";
		std::getline(std::cin, secret);
	}

	int index;
	if (total_contacts < 8)
	{
		index = total_contacts;
		total_contacts++;
	}
	else
	{
		index = next_index;
		next_index++;
		if (next_index == 9)
			next_index = 0;
	}

	contacts[index].set_contact(firstName, lastName, nickname, phoneNumber, secret);
	std::cout << "Contact added !" << std::endl;
}

bool	valid_index(std::string index)
{
	if (index.empty())
		return false;
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7')
		return true;
	return false;
}

void	PhoneBook::search_contact()
{
	std::string input;

	std::cout << "Select index to see more contact information:" << std::endl;
	std::getline(std::cin, input);
	while (!valid_index(input))
	{
		std::cout << "Invalid index !" << std::endl;
		std::cout << "Select a valid index to see contact information:" << std::endl;
		std::getline(std::cin, input);
	}
	int index = input[0] - '0';
	if (contacts[index].is_empty())
		std::cout << "Empty contact !" << std::endl;
	else
		contacts[index].display_contact_info();
}
		
void	PhoneBook::display_contacts()
{
	if (total_contacts == 0)
	{
		std::cout << "No contacts !" << std::endl;
		return ;
	}

	std::cout << "CONTACTS RESUME" << std::endl;
	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	int index = 0;
	while (index < total_contacts)
	{
		if (!contacts[index].is_empty())
			contacts[index].display_contact_resume(index);
		index++;
	}

	search_contact();
}