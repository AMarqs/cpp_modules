#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Assassin");
	FragTrap f("HighFive");

	a.attack("Victim");
	f.attack("Victim");
	f.highFivesGuys();

	return 0;
}