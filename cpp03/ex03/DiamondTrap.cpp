#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = "Diamonymous";
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	_name = name;
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
}

DiamondTrap::~DiamondTrap()
{ std::cout << "DiamondTrap default destructor called" << std::endl; }

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		_name = copy._name;
		_hit = copy._hit;
		_energy = copy._energy;
		_damage = copy._damage;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "DiamondTrap " << _name << " can't attack because is dead!" << std::endl;
	else if (_energy == 0)
		std::cout << "DiamondTrap " << _name << " can't attack because it doesn't have energy points!" << std::endl;
	else
		ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	if (_hit == 0)
		std::cout << "DiamondTrap " << _name << " is dead" << std::endl;
	else
	{
		std::cout << "DiamondTrap name: " << _name << std::endl;
		std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
	}
}