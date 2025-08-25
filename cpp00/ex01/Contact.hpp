#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:

		std::string	firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;

	public:

		Contact();
		~Contact();

		void	set_contact(std::string fN, std::string lN, std::string nN, std::string pN, std::string s);

		std::string get_fN() const;
        std::string get_lN() const;
        std::string get_nN() const;

		void	display_contact_info() const;
		void	display_contact_resume(int index) const;
		bool	is_empty() const;


};

#endif