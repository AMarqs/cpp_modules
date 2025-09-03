#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Scanonymous")
{
	_hit = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "Scav default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "Scav constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << "Scav copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "Scav copy assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

ScavTrap::~ScavTrap()
{ std::cout << "Scav default destructor called" << std::endl; }

void ScavTrap::attack(const std::string& target)
{
	if (_hit == 0 && _energy == 0)
		std::cout << "ScavTrap " << _name << " can't attack - 0 hit and energy points!" << std::endl;
	else if (_hit == 0)
		std::cout << "ScavTrap " << _name << " can't attack - 0 hit points!" << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " can't attack - 0 energy points!" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
		_energy--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}