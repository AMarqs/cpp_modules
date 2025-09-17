#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Franonymous")
{
	std::cout << "Frag default constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::~FragTrap()
{ std::cout << "FragTrap default destructor called" << std::endl; }

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = copy;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit = copy._hit;
		_energy = copy._energy;
		_damage = copy._damage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	if (_hit == 0)
		std::cout << "FragTrap " << _name << " can't give a high-five because is dead!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " request HIGH-FIVE!" << std::endl;
}