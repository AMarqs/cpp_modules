#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include "PhoneBook.hpp"

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

static void remove_tabs(std::string & str)
{
	size_t pos = 0;

	pos = str.find_first_not_of("\n\t\f\v ");
	if (pos != std::string::npos)
		str = str.substr(pos);

	pos = str.find_last_not_of("\n\t\f\v ");
	if (pos != std::string::npos)
		str = str.substr(0, pos + 1);

	for (size_t i = 0; i < str.size(); i++) {
		if (std::strchr("\n\t\f\v", str[i])) str[i] = ' ';
	}
}

void	PhoneBook::add_contact()
{
	std::string firstName, lastName, nickname, phoneNumber, secret;

	std::cout << "Fill the contact fields" << std::endl;

	std::cout << "First Name (max 20 characters): ";
	std::getline(std::cin, firstName);
	if (std::cin.eof())
		exit(1);
	while (firstName.length() > 20)
	{
		std::cout << "Maximum 20 characters for First Name" << std::endl;
		std::cout << "First Name (max 20 characters): ";
		std::getline(std::cin, firstName);
		if (std::cin.eof())
			exit(1);
	}
	remove_tabs(firstName);

	std::cout << "Last Name (max 20 characters): ";
	std::getline(std::cin, lastName);
	if (std::cin.eof())
		exit(1);
	while (lastName.length() > 20)
	{
		std::cout << "Maximum 20 characters for Last Name" << std::endl;
		std::cout << "Last Name (max 20 characters): ";
		std::getline(std::cin, lastName);
		if (std::cin.eof())
			exit(1);
	}
	remove_tabs(lastName);

	std::cout << "Nickname (max 20 characters): ";
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		exit(1);
	while (nickname.length() > 20)
	{
		std::cout << "Maximum 20 characters for Nickname" << std::endl;
		std::cout << "Nickname (max 20 characters): ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			exit(1);
	}
	remove_tabs(nickname);
	
	std::cout << "Phone Number (max 9 numbers): ";
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
		exit(1);
	while (phoneNumber.length() > 9 || !is_number(phoneNumber))
	{
		std::cout << "Maximum 9 numbers for Phone Number" << std::endl;
		std::cout << "Phone Number (max 9 numbers): ";
		std::getline(std::cin, phoneNumber);
		if (std::cin.eof())
			exit(1);
	}

	std::cout << "Darkest Secret (max 40 characters): ";
	std::getline(std::cin, secret);
	if (std::cin.eof())
		exit(1);
	while (secret.length() > 40)
	{
		std::cout << "Maximum 40 characters for Darkest Secret" << std::endl;
		std::cout << "Darkest Secret (max 40 characters): ";
		std::getline(std::cin, secret);
		if (std::cin.eof())
			exit(1);
	}
	remove_tabs(secret);

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
	if (std::cin.eof())
		exit(1);
	while (!valid_index(input))
	{
		std::cout << "Invalid index !" << std::endl;
		std::cout << "Select a valid index to see contact information:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
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