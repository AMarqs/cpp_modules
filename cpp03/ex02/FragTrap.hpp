#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:

		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& copy);

		void highFivesGuys(void);
};

#endif