#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	public:

		Zombie();
		~Zombie();

		void announce( void );
		void create( std::string zombie_name );

	private:

		std::string name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif