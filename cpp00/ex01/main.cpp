#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void title()
{
	std::cout << "╔═══════════════════════════════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║                                                                                           ║" << std::endl;
	std::cout << "║       ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗       ║" << std::endl;
	std::cout << "║       ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝       ║" << std::endl;
	std::cout << "║       ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝        ║" << std::endl;
	std::cout << "║       ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗        ║" << std::endl;
	std::cout << "║       ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗       ║" << std::endl;
	std::cout << "║       ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝       ║" << std::endl;
	std::cout << "║                                                                                           ║" << std::endl;
	std::cout << "╚═══════════════════════════════════════════════════════════════════════════════════════════╝" << std::endl;
}

void commands()
{
	std::cout << "┌───────────────────────────────────────────────────────────────────────────────────────────┐" << std::endl;
	std::cout << "│                                           OPTIONS                                         │" << std::endl;
	std::cout << "├───────────────────────────────────────────────────────────────────────────────────────────┤" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "│  ADD     → Add a new contact to your phonebook                                            │" << std::endl;
	std::cout << "│            Parameters: First Name, Last Name, Nickname, Phone Number, and Darkest Secret  │" << std::endl;
	std::cout << "│            Note: Maximum 8 contacts. New contacts will replace the oldest ones!           │" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "│  SEARCH  → Display all contacts and view detailed information                             │" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "│  EXIT    → Close the phonebook                                                            │" << std::endl;
	std::cout << "│            All contacts will be permanently deleted !!!                                   │" << std::endl;
	std::cout << "│                                                                                           │" << std::endl;
	std::cout << "└───────────────────────────────────────────────────────────────────────────────────────────┘" << std::endl;
	std::cout << std::endl;
}

int main()
{
	PhoneBook	phoneBook;
	std::string	option;

	title();
	commands();

	while (true)
	{
		std::cout << "Select an option (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, option);

		if (option == "ADD")
			phoneBook.add_contact();
		else if (option == "SEARCH")
			phoneBook.display_contacts();
		else if (option == "EXIT")
		{
			std::cout << "PhoneBook closed !" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid option !" << std::endl;
	}
	return (0);
}


