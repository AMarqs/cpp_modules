#include "ClapTrap.hpp"

int main()
{
	ClapTrap A("A");

	A.attack("B");
	A.takeDamage(3);
	A.beRepaired(5);

	return 0;
}