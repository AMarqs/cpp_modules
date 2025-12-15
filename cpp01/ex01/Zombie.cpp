#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default zombie appears" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " has dead" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::create( std::string name )
{
	_name = name;
}