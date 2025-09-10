#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{	
	const AAnimal* a = new Dog();
	const AAnimal* b = new Cat();

	delete a; //should not create a leak
	delete b;

	const int N = 10;
	AAnimal* animals[N];
	
	for (int i = 0; i < N/2; i++)
		animals[i] = new Dog();
	for (int i = N/2; i < N; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();

	for (int i = 0; i < N; i++)
		delete animals[i];

	// Abstract test
	// const AAnimal* c = new AAnimal();
	// delete c;

	return 0;
}