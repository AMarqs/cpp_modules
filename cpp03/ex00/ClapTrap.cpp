#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Anonymous"), _hit(10), _energy(10), _damage(0)
{ std::cout << "Default constructor called" << std::endl; }

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0)
{ std::cout << "Constructor called" << std::endl; }

ClapTrap::ClapTrap(const ClapTrap& copy) : _name(copy._name), _hit(copy._hit), _energy(copy._energy), _damage(copy._damage)
{ std::cout << "Copy constructor called" << std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	std::cout << "Copy assignment operator called" << std::endl; 
	if (this != &copy) {
		_name = copy._name;
		_hit = copy._hit;
		_energy = copy._energy;
		_damage = copy._damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{ std::cout << "Default destructor called" << std::endl; }

void ClapTrap::attack(const std::string& target)
{
	if (_hit == 0 && _energy == 0)
		std::cout << "ClapTrap " << _name << " can't attack - 0 hit and energy points!" << std::endl;
	else if (_hit == 0)
		std::cout << "ClapTrap " << _name << " can't attack - 0 hit points!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " can't attack - 0 energy points!" << std::endl;
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
	if (amount >= _hit)
		_hit = 0;
	else
		_hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired because is dead!" << std::endl;
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired - 0 energy points!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " regains " << amount << " hit points!" << std::endl;
		_energy--;
		if ((_hit + amount) >= 10)
			_hit = 10;
		else
			_hit += amount;
	}
}