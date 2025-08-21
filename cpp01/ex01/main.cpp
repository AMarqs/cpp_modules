#include "Zombie.hpp"

int main()
{
	std::string name;
	int N = 0;

	std::cout << "Insert zombie name: ";
	std::cin >> name;
	std::cout << "Insert number of zombies: ";
	std::cin >> N;

    Zombie* horde = zombieHorde(N, name);
    for (int i = 0; i < N; ++i)
        horde[i].announce();
    delete[] horde;
	return 0;
}