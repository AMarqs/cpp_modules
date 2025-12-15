#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "[Cat] Default constructor called" << std::endl; }
Cat::~Cat() { std::cout << "[Cat] Destructor called" << std::endl; }
Cat::Cat(const Cat& copy) : Animal(copy) { std::cout << "[Cat] Copy constructor called" << std::endl; }
Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	if (this != &copy)
		Animal::operator=(copy);
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Miau!" << std::endl;
}