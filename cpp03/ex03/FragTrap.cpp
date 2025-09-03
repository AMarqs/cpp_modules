#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Franonymous")
{
	_hit = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "Frag default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 100;
	_damage = 30;
	std::cout << "Frag constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "Frag copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "Frag copy assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

FragTrap::~FragTrap()
{ std::cout << "Frag default destructor called" << std::endl; }

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " request HIGH-FIVE!" << std::endl;
}