#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "---------- WRONG CASE ----------" << std::endl;

	const WrongAnimal* fakeAnimal = new WrongAnimal();
	const WrongAnimal* fakeCat = new WrongCat();

	std::cout << fakeCat->getType() << " " << std::endl;
	std::cout << fakeAnimal->getType() << " " << std::endl;
	fakeCat->makeSound();
	fakeAnimal->makeSound();

	delete fakeAnimal;
	delete fakeCat;

	return 0;
}