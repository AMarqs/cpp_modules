#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	public:

		// Constructor
		PhoneBook();

		void	add_contact();
		void	search_contact();
		void	display_contacts();

		// Destructor
		~PhoneBook();

	private:
	
		Contact	contacts[8];
		int		total_contacts;
		int		next_index;
	
};

#endif