#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap a("Assassin");
	ScavTrap s("Guardian");

	a.attack("Victim");
	s.attack("Victim");
	s.guardGate();

	return 0;
}
