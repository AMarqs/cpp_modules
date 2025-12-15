#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
	std::cout << "Default zombie appears" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << _name << " zombie appears" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " has dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}