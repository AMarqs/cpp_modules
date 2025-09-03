#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Diamond_clap_name"), ScavTrap(), FragTrap()
{
	_name = "Diamonymous";
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << "Diamond default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << "Diamond constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "Diamond copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	std::cout << "Diamond copy assignment operator called" << std::endl;
	if (this != &copy)
		ClapTrap::operator=(copy);
	return *this;
}

DiamondTrap::~DiamondTrap()
{ std::cout << "Diamond default destructor called" << std::endl; }

void DiamondTrap::attack(const std::string& target)
{
	if (_hit == 0 && _energy == 0)
		std::cout << "Diamond " << _name << " can't attack - 0 hit and energy points!" << std::endl;
	else if (_hit == 0)
		std::cout << "Diamond " << _name << " can't attack - 0 hit points!" << std::endl;
	else if (_energy == 0)
		std::cout << "Diamond " << _name << " can't attack - 0 energy points!" << std::endl;
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