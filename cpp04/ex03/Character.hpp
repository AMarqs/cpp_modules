#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class Character
{
	public:

		Character();
		Character(std::string const & type);
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		~Character();

};

#endif