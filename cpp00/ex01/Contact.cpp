#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), secret("") {}
Contact::~Contact() {}

void	Contact::set_contact(std::string fN, std::string lN, std::string nN, std::string pN, std::string s)
{
	firstName = fN;
	lastName = lN;
	nickname = nN;
	phoneNumber = pN;
	secret = s;
}

std::string Contact::get_fN() const { return firstName; }
std::string Contact::get_lN() const { return lastName; }
std::string Contact::get_nN() const { return nickname; }

void	Contact::display_contact_info() const
{
	std::cout << "CONTACT INFORMATION" << std::endl;
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;
}

std::string formatField(std::string field)
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void	Contact::display_contact_resume(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << formatField(firstName);
	std::cout << "|" << std::setw(10) << formatField(lastName);
	std::cout << "|" << std::setw(10) << formatField(nickname);
	std::cout << "|" << std::endl;
}

bool	Contact::is_empty() const
{
	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || secret.empty())
		return true;
	return false;
}

