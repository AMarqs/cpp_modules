#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << "[Dog] Default constructor called" << std::endl; }
Dog::Dog(const Dog& copy) : Animal(copy) { std::cout << "[Dog] Copy constructor called" << std::endl; }
Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	if (this != &copy) {
		Animal::operator=(copy);
	}
	return *this;
}
Dog::~Dog() { std::cout << "[Dog] Destructor called" << std::endl; }

void	Dog::makeSound() const
{
	std::cout << "Guau!" << std::endl;
}