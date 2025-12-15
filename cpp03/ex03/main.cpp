#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap D("Assassin");

	D.attack("Victim");
	D.whoAmI();
	D.takeDamage(40);
	D.beRepaired(10);

	return 0;
}