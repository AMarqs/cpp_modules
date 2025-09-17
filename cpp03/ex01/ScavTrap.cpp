#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Scanonymous")
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::~ScavTrap()
{ std::cout << "ScavTrap default destructor called" << std::endl; }

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit = copy._hit;
		_energy = copy._energy;
		_damage = copy._damage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "ScavTrap " << _name << " can't attack because is dead!" << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " can't attack because it doesn't have energy points!" << std::endl;
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