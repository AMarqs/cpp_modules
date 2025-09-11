#include "Zombie.hpp"

int main()
{
	Zombie	test("Test");
	test.announce();

	randomChump("Random");
	
	Zombie *newZ = newZombie("New");
	newZ->announce();
	delete newZ;

	return 0;
}