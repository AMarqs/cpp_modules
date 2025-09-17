#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Anonymous"), _hit(10), _energy(10), _damage(0)
{ std::cout << "Default constructor called" << std::endl; }

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0)
{ std::cout << "Constructor called" << std::endl; }

ClapTrap::~ClapTrap()
{ std::cout << "Default destructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = copy._name;
	_hit = copy._hit;
	_energy = copy._energy;
	_damage = copy._damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "Copy assignment operator called" << std::endl; 
	if (this != &copy)
	{
		_name = copy._name;
		_hit = copy._hit;
		_energy = copy._energy;
		_damage = copy._damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit == 0)
		std::cout << "ClapTrap " << _name << " can't attack because is dead!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " can't attack because it doesn't have energy points!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
		_energy--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit == 0)
	{
		std::cout << "ClapTrap " << _name << " was already dead!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	_hit -= (int)amount;
	if (_hit < 0)
		_hit = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired because is dead!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired because it doesn't have energy points!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " regains " << amount << " hit points!" << std::endl;
		_energy--;
		_hit += amount;
	}
	if (_hit > 10)
		_hit = 10;
}