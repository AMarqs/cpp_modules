#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
	
		Contact	contacts[8];
		int		total_contacts;
		int		next_index;

	public:

		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	search_contact();
		void	display_contacts();
};

#endif