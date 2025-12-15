#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{	
	const Animal* a = new Dog();
	const Animal* b = new Cat();

	delete a; //should not create a leak
	delete b;

	const int N = 10;
	Animal* animals[N];
	
	for (int i = 0; i < N/2; i++)
		animals[i] = new Dog();
	for (int i = N/2; i < N; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();

	for (int i = 0; i < N; i++)
		delete animals[i];
	
	std::cout << std::endl << "----- DEEP COPIES -----" << std::endl;
	Dog d1;
	d1.setBrain(0, "Cazar");
	Dog d2 = d1;
	d2.setBrain(0, "Dormir");
	std::cout << d1.getBrain(0) << " vs " << d2.getBrain(0) << std::endl;

	return 0;
}